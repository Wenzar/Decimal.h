#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int add_return = 0;
  s21_big_decimal current_value_1 = {0};
  s21_big_decimal current_value_2 = {0};
  s21_big_decimal big_result = {0};
  s21_decimal fabs_result = {{0, 0, 0, 0}};
  s21_decimal max_num = {{0, 0, 3794707712, 0}};  // 7e28

  big_initialization(value_1, &current_value_1);
  big_initialization(value_2, &current_value_2);

  if ((!big_getBit(current_value_1, 223) &&
       !big_getBit(current_value_2, 223)) ||
      (big_getBit(current_value_1, 223) && big_getBit(current_value_2, 223))) {
    multiplication(current_value_1, current_value_2, &big_result);
    bank_round(big_result, &big_result);
    big_uninitilization(big_result, result);

    setBit(result, 127, 0);
    fabs_result.bits[0] = result->bits[0];
    fabs_result.bits[1] = result->bits[1];
    fabs_result.bits[2] = result->bits[2];
    fabs_result.bits[3] = result->bits[3];

    if (s21_is_greater_or_equal(fabs_result, max_num)) {
      add_return = 1;
    }

    result->bits[3] = value_1.bits[3] + value_2.bits[3];

  } else if ((!big_getBit(current_value_1, 223) &&
              big_getBit(current_value_2, 223)) ||
             (big_getBit(current_value_1, 223) &&
              !big_getBit(current_value_2, 223))) {
    multiplication(current_value_1, current_value_2, &big_result);
    big_setBit(&big_result, 223, 1);
    bank_round(big_result, &big_result);
    big_uninitilization(big_result, result);

    fabs_result.bits[0] = result->bits[0];
    fabs_result.bits[1] = result->bits[1];
    fabs_result.bits[2] = result->bits[2];
    fabs_result.bits[3] = result->bits[3];
    max_num.bits[3] = 0b10000000000000000000000000000000;  //-7e28

    if (s21_is_less_or_equal(fabs_result, max_num)) {
      add_return = 2;
    }

    result->bits[3] = value_1.bits[3] + value_2.bits[3];
  }
  return add_return;
}