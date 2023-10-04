#include "s21_decimal.h"
int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  s21_big_decimal big_copy_decimal = {0};
  big_initialization(value, &big_copy_decimal);
  while (find_out_the_degree(big_copy_decimal)) {
    error = demotion_scale(&big_copy_decimal);
  }

  // Obrabotka okryglenia k blijaishemy celomy
  // printf("\nbig_copy_decimal.bits: %u\n",big_copy_decimal.bits[0]);
  float result_float = 0;
  s21_from_decimal_to_float(value, &result_float);
  result_float = result_float - (int)result_float;
  // printf("\result_floatinHERRE.bits: %f\n",result_float);
  if (fabs(result_float) >= 0.5) {
    big_copy_decimal.bits[0]++;
    if (value.bits[3] > MY_INT_MAX && result_float <= -0.5) {
      big_copy_decimal.bits[0]--;
    }
  }

  unsigned int remainder = 0;
  while (big_copy_decimal.bits[3] || big_copy_decimal.bits[4] ||
         big_copy_decimal.bits[5]) {
    if (!big_copy_decimal.bits[4] && !big_copy_decimal.bits[5] &&
        big_copy_decimal.bits[3] / 10 == 0) {
      remainder = big_copy_decimal.bits[3];
      break;
    }
    big_shift_right(&big_copy_decimal, 1);
  }
  if (remainder >= 5) {
    big_addition(big_copy_decimal, one_big_decimal, &big_copy_decimal);
  }
  big_uninitilization(big_copy_decimal, result);
  return error;
}