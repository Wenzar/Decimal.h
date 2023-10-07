#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal current_value_1 = {0};
  s21_big_decimal current_value_2 = {0};
  s21_big_decimal big_result = {0};
  int add_return = 0;
  big_initialization(value_1, &current_value_1);
  big_initialization(value_2, &current_value_2);
  normalization(&current_value_1, &current_value_2);
  int scale = find_out_the_degree(current_value_1);
  if ((!big_getBit(current_value_1, 223) &&
       !big_getBit(current_value_2, 223)) ||
      (big_getBit(current_value_1, 223) && big_getBit(current_value_2, 223))) {
    multiplication(current_value_1, current_value_2, &big_result);
    add_return = bank_round(big_result, &big_result);
    big_uninitilization(big_result, result);
  } else if ((!big_getBit(current_value_1, 223) &&
              big_getBit(current_value_2, 223)) ||
             (big_getBit(current_value_1, 223) &&
              !big_getBit(current_value_2, 223))) {
    multiplication(current_value_1, current_value_2, &big_result);
    big_setBit(&big_result, 223, 1);
    add_return = bank_round(big_result, &big_result);
    if (add_return) {
      add_return = 2;
    }
    big_uninitilization(big_result, result);
  }
  result->bits[3] = scale;
  return add_return;
}