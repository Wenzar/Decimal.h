#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2)
{
    s21_big_decimal current_value_1 = {0};
    s21_big_decimal current_value_2 = {0};
   // s21_big_decimal big_result = {0};
    big_initialization(value_1, &current_value_1);
    big_initialization(value_2, &current_value_2);
    normalization(&current_value_1, &current_value_2);
    return !mantis_s21_is_equal(current_value_1, current_value_2);
}