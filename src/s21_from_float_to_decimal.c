#include <math.h>

#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  dst->bits[0]=0;
  dst->bits[1]=0;
  dst->bits[2]=0;
  dst->bits[3]=0;
  int return_value = 0;
  if (src < -1e30) {
    return_value = 2;
  }
  else if(isinf(src) || isnan(src)) {
    return_value = 1;
  }
 else {
    if (src != 0) {
      int sign = *(int *)&src >> 31;
      int exp = ((*(int *)&src & ~0x80000000) >> 23) - 127;
      double buffer = (double)fabs(src);
      int off = 0;
      for (; off < 28 && (int)buffer / (int)pow(2, 21) == 0; buffer *= 10, off++) {
      }
      buffer = round(buffer);
      if (off <= 28 && (exp > -94 && exp < 96)) {
        float_bits mantis = {0};
        buffer = (float)buffer;
        for (; fmod(buffer, 10) == 0 && off > 0; off--, buffer /= 10) {
        }
        mantis.float_number = buffer;
        exp = ((*(int *)&mantis.float_number & ~0x80000000) >> 23) - 127;
        dst->bits[exp / 32] |= 1 << exp % 32;
        for (int i = exp - 1, j = 22; j >= 0; i--, j--)
          if ((mantis.uint_number & (1 << j)) != 0)
            dst->bits[i / 32] |= 1 << i % 32;
        dst->bits[3] = (sign << 31) | (off << 16);
      }
    }
  }
  return return_value;
}
