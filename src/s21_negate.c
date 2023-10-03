#include "s21_decimal.h"
int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  if (getBit(*result, 127)) {
    setBit(result, 127, 0);
  } else {
    setBit(result, 127, 1);
  }
  return 0;
}