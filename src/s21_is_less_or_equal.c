#include "s21_decimal.h"

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  s21_big_decimal current_value_1 = {0};
  s21_big_decimal current_value_2 = {0};
  big_initialization(value_1, &current_value_1);
  big_initialization(value_2, &current_value_2);
  normalization(&current_value_1, &current_value_2);
  if (!getBit(value_1, 127) && !getBit(value_2, 127)) {
    result = mantis_is_less_or_equal(current_value_1, current_value_2);
  } else if (getBit(value_1, 127) && getBit(value_2, 127)) {
    result = mantis_is_greater_or_equal(current_value_1, current_value_2);
  } else if (getBit(value_1, 127) && !getBit(value_2, 127)) {
    result = 1;
  } else if (!getBit(value_1, 127) && getBit(value_2, 127)) {
  }
  return result;
}