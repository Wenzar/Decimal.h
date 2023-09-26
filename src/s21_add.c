#include "s21_decimal.h"
#include <stdio.h>

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{

  s21_decimal decimal_value;

  // Пример инициализации положительного числа 123.456 (значение для примера)
  initialize_s21_decimal(&decimal_value, 0, 7, 123456);

  // Доступ к частям числа
  int sign = (decimal_value.bits[3] >> 31) & 1;
  int exponent = (decimal_value.bits[3] >> 16) & 0xFF;
  int mantissa = (decimal_value.bits[0]) | ((long long)decimal_value.bits[1] << 32) | ((long long)decimal_value.bits[2] << 64);

  // Вывод значений
  printf("Sign: %d\n", sign);
  printf("Exponent: %d\n", exponent);
  printf("Mantissa: %lld\n", mantissa);

  return 0;
}