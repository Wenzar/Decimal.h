#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  s21_big_decimal big_copy_decimal = {0};
  big_initialization(value, &big_copy_decimal);
  while (find_out_the_degree(big_copy_decimal) > 1) {
    error = demotion_scale(&big_copy_decimal);
  }
  if (my_remainder(big_copy_decimal) >= 5 &&
      find_out_the_degree(big_copy_decimal)) {
    error = demotion_scale(&big_copy_decimal);
    big_addition(big_copy_decimal, one_big_decimal, &big_copy_decimal);
  } else {
    if (find_out_the_degree(big_copy_decimal)) {
      error = demotion_scale(&big_copy_decimal);
    }
  }

  big_uninitilization(big_copy_decimal, result);
  return error;
}