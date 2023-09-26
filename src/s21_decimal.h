#ifndef STRING_H
#define STRING_H

#include <stdio.h>

typedef struct
{
  int bits[4];
} s21_decimal;

typedef struct
{
  unsigned int bits[7];
} s21_big_decimal;

extern s21_decimal ten;
extern s21_decimal decimal_null;
extern s21_decimal one_decimal;
extern s21_big_decimal one_big_decimal;
extern s21_big_decimal big_ten;
extern s21_big_decimal big_decimal_null;

// main functions

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// help functions

int difference(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result);
int getBit(s21_decimal value, int bit);
int setBit(s21_decimal *value, int bit, int num);
int find_out_the_degree(s21_big_decimal scale);
int degree_comparison(s21_big_decimal value_1, s21_big_decimal value_2);
void normalization(s21_big_decimal *value_1, s21_big_decimal *value_2);
void big_uninitilization(s21_big_decimal big_value, s21_decimal *smal_value);
int big_getBit(s21_big_decimal value, int bit);
int big_setBit(s21_big_decimal *value, int bit, int num);
int demotion_scale(s21_big_decimal *value);
int raise_scale(s21_big_decimal *value);
int big_addition(s21_big_decimal current_value_1, s21_big_decimal current_value_2, s21_big_decimal *big_result);
void big_initialization(s21_decimal small_value, s21_big_decimal *big_value);
void division_by_integer(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result);
int mantis_is_less_or_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int mantis_is_less(s21_big_decimal value_1, s21_big_decimal value_2);
void big_shift_right(s21_big_decimal *value, int step);
int shift_right(s21_decimal *value, int step);
int step_left(int bits_decimal);
int multiplication(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result);
int mantis_is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int mantis_s21_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int bank_round(s21_big_decimal value, s21_big_decimal *result);
int parity(int value);
int check_remainder(int value);
int check_dop_decimal(s21_big_decimal value);
int check_five_number(s21_big_decimal value);
int mantis_is_greater_or_equal(s21_big_decimal value_1, s21_big_decimal value_2);
void shift_left(s21_big_decimal *value, int step);

#endif