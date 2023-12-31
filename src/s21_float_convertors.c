#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  int return_value = 0;
  if (src <= -1e30) {
    return_value = 2;
  } else if (isinf(src) || isnan(src)) {
    return_value = 1;
  } else {
    if (src != 0) {
      int minos = *(int *)&src >> 31;
      int exponent = ((*(int *)&src & ~0x80000000) >> 23) - 127;
      double buffer = (double)fabs(src);
      int counter = 0;
      for (; counter < 28 && (int)buffer / (int)pow(2, 21) == 0;
           buffer *= 10, counter++) {
      }
      buffer = round(buffer);
      if (counter <= 28 && (exponent > -94 && exponent < 96)) {
        float_bits mantis = {0};
        buffer = (float)buffer;
        for (; fmod(buffer, 10) == 0 && counter > 0; counter--, buffer /= 10) {
        }
        mantis.float_number = buffer;
        exponent = ((*(int *)&mantis.float_number & ~0x80000000) >> 23) - 127;
        dst->bits[exponent / 32] |= 1 << exponent % 32;
        for (int i = exponent - 1, j = 22; j >= 0; i--, j--)
          if ((mantis.uint_number & (1 << j)) != 0)
            dst->bits[i / 32] |= 1 << i % 32;
        dst->bits[3] = (minos << 31) | (counter << 16);
      }
    }
  }
  return return_value;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double buffer = (double)*dst;
  for (int i = 0; i < 96; i++) {
    buffer += getBit(src, i) * pow(2, i);
  }
  buffer *= pow(10, -small_find_out_the_degree(src));
  if (getBit(src, 127)) {
    buffer *= -1;
  }
  *dst = buffer;
  return 0;
}