#ifndef s21_decimal_TEST_H
#define s21_decimal_TEST_H

#include <check.h>
#include <stdio.h>
#include <limits.h>

#include "../s21_decimal.h"

Suite *s21_add_suite(void);
Suite *s21_div_suite(void);
Suite *s21_mul_suite(void);
Suite *s21_sub_suite(void);

void run_testcase(Suite *testcase);

#endif //  s21_decimal_TEST_H