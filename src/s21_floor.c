#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int error = 0;

  s21_big_decimal big_copy_decimal = {0};
  big_initialization(value, &big_copy_decimal);

  while (find_out_the_degree(big_copy_decimal)) {
    error = demotion_scale(&big_copy_decimal);
  }

  while (big_copy_decimal.bits[3] || big_copy_decimal.bits[4] ||
         big_copy_decimal.bits[5]) {
    big_shift_right(&big_copy_decimal, 1);
  }
  big_uninitilization(big_copy_decimal, result);

  // Проверяем была ли дробная часть у числа, если была и число отрицательное то
  // добавляем 1 к bits[0]
  s21_decimal income_value = {{value.bits[3], 0, 0, 0}};
  s21_decimal compare_value = {{0b10000000000000010000000000000000, 0, 0, 0}};

  if (s21_is_greater_or_equal(income_value, compare_value)) {
    result->bits[0]++;
  }
  return error;
}