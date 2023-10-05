#include "s21_decimal.h"

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

