#include "s21_decimal.h"

int last_bit(s21_decimal value);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int sign = 0;
  if (src < 0) {
    src = -src;
    setBit(dst, 127, 1);
    sign = 1;
  }
  int error = 0;
  int int_part = src;

  int scale = 0;

  float x = 0;
  double copy_num = src - (int)src;
  double remainder = modff(copy_num, &x);
  while (modff(copy_num, &x)) {
    scale++;
    copy_num *= 10;
    remainder = (int)copy_num;
  }

  dst->bits[0] = remainder;

  dst->bits[3] = scale << 16;
  s21_decimal new = {0};
  s21_decimal copy_res = {0};
  new.bits[0] = int_part;
  s21_add(*dst, new, &copy_res);
  *dst = copy_res;
  setBit(dst, 127, sign);
  // printf("%u", dst->bits[0]);
  return error;
}

int last_bit(s21_decimal value) {
  int bit = 0;
  for (int i = 0; i <= 95; i++) {
    int new_bit = 0;
    for (int j = i + 1; j <= 95; j++) {
      if (getBit(value, j)) {
        new_bit = 1;
      }
    }
    if (new_bit == 0) {
      bit = i;
      break;
    }
  }
  return bit;
}