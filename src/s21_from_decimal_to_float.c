#include "s21_decimal.h"

int get_the_rest(s21_big_decimal value);
int get_number(unsigned int value);
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  int sign = 1;
  s21_big_decimal copy_big_decimal = {0};
  big_initialization(src, &copy_big_decimal);
  if (big_getBit(copy_big_decimal, 223)) {
    sign = 0;
    big_setBit(&copy_big_decimal, 223, 0);
  }
  while (find_out_the_degree(copy_big_decimal)) {

    demotion_scale(&copy_big_decimal);
  }
  for (int i = 1; i <= 5; i++) {
    if (copy_big_decimal.bits[i]) {
      error = 1;
    }
  }

  unsigned int integer_part = copy_big_decimal.bits[0];

  big_initialization(src, &copy_big_decimal);
  int remainder = 0;
  remainder = get_the_rest(copy_big_decimal);

  if (get_number(integer_part) < 7) {

    while ((get_number(remainder) + get_number(integer_part)) > 8) {
      remainder /= 10;
    }

    if (remainder % 10 >= 5) {
      remainder /= 10;
      remainder += 1;

    } else {
      remainder /= 10;
    }
    double my_number = remainder;

    while (my_number > 1) {
      my_number /= 10;
    }

    my_number += integer_part;
    *dst = my_number;
    if (!sign) {
      *dst *= -1;
    }
  } else {

    while (get_number(integer_part) > 8) {
      integer_part /= 10;
    }

    if (integer_part % 10 >= 5) {
      integer_part /= 10;
      integer_part += 1;
    }

    else {
      integer_part /= 10;
    }
    *dst = integer_part;
    if (!sign) {
      *dst *= -1;
    }
  }
  return error;
}

int get_the_rest(s21_big_decimal value) {

  int remainder = 0;
  int count = 0;
  while (find_out_the_degree(value)) {
    remainder += value.bits[0] % 10 * pow(10, count);
    demotion_scale(&value);
    count++;
  }
  return remainder;
}

int get_number(unsigned int value) {

  int count = 1;
  while (value / 10 != 0) {
    count++;
    value /= 10;
  }

  return count;
}
