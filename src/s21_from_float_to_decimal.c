#include "s21_decimal.h"
#include <math.h>

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int sign = 0;
  if (src < 0) {
    src = -src;
    setBit(dst, 127, 1);
    sign = 1;
  }

  int error = 0;
  int int_part = (int)src;
  float fractional_part = src - int_part;

  int scale = 0;

  while (fractional_part != 0.0 && scale < countFractionalDigits(src)) {
    fractional_part *= 10;
    int digit = (int)roundf(fractional_part);
    dst->bits[0] = dst->bits[0] * 10 + digit;
    fractional_part -= digit;
    scale++;
  }

  dst->bits[3] = scale << 16;
  s21_decimal new = {0};
  s21_decimal copy_res = {0};
  new.bits[0] = int_part;
  s21_add(*dst, new, &copy_res);
  *dst = copy_res;
  setBit(dst, 127, sign);
  // printf("\nres: \n%u %u\n", dst->bits[1], dst->bits[0]);
  return error;
}
