#ifndef s21_decimal_TEST_H
#define s21_decimal_TEST_H

#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

Suite *s21_add_suite(void);
Suite *s21_div_suite(void);
Suite *s21_mul_suite(void);
Suite *s21_sub_suite(void);
Suite *s21_is_equal_suite(void);
Suite *s21_floor_suite(void);
Suite *s21_round_suite(void);
Suite *s21_from_decimal_to_float_suite(void);
Suite *s21_suite_from_decimal_to_int(void);
Suite *s21_suite_from_int_to_decimal(void);
Suite *s21_from_float_to_decimal_test(void);
Suite *s21_suite_is_greater_or_equal(void);
Suite *s21_suite_is_greater(void);
Suite *s21_suite_is_less_or_equal(void);
Suite *s21_suite_is_less(void);
Suite *s21_suite_is_not_equal(void);
Suite *s21_suite_truncate(void);
Suite *s21_suite_negate(void);

void run_testcase(Suite *testcase);

#endif //  s21_decimal_TEST_H