#ifndef STRING_H
#define STRING_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MY_INT_MAX 2147483648
#define MAX_DEC_FLOAT powf(2.0f, 96.0f) - 1.0
#define MIN_DEC_FLOAT -powf(2.0f, 96.0f) + 1.0

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
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
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);

// help functions
// void small_shift_left(s21_decimal *value, int step);
int small_find_out_the_degree(s21_decimal scale);
int check_osnova(s21_big_decimal value);
int check_error(s21_decimal value_1, s21_decimal value_2);
int difference(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result);
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
int big_addition(s21_big_decimal current_value_1,
                 s21_big_decimal current_value_2, s21_big_decimal *big_result);
void big_initialization(s21_decimal small_value, s21_big_decimal *big_value);
void division_by_integer(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
int mantis_is_less_or_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int mantis_is_less(s21_big_decimal value_1, s21_big_decimal value_2);
void big_shift_right(s21_big_decimal *value, int step);
int shift_right(s21_decimal *value, int step);
int step_left(int bits_decimal);
int multiplication(s21_big_decimal value_1, s21_big_decimal value_2,
                   s21_big_decimal *result);
int mantis_is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int mantis_s21_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int bank_round(s21_big_decimal value, s21_big_decimal *result);
int parity(int value);
int check_remainder(int value);
int check_dop_decimal(s21_big_decimal value);
int check_five_number(s21_big_decimal value);
int mantis_is_greater_or_equal(s21_big_decimal value_1,
                               s21_big_decimal value_2);
void shift_left(s21_big_decimal *value, int step);
int countFractionalDigits(float num);
float s21_rand_r(float a, float b);

#endif