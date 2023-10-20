#include "s21_decimal_test.h"

// START_TEST(div_0) {
//   s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal val2 = {{2, 0, 0, 0}};
//   s21_decimal res = {{0}};
//   ck_assert_int_eq(0, s21_div(val1, val2, &res));
// }
// END_TEST

// START_TEST(div_1) {
//   s21_decimal val1 = {{2, 0, 0, 0}};
//   s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal res;
//   ck_assert_int_eq(0, s21_div(val1, val2, &res));
// }
// END_TEST

// START_TEST(div_2) {
//   s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal res = {{0}};
//   ck_assert_int_eq(0, s21_div(val1, val2, &res));
// }
// END_TEST

// START_TEST(div_3) {
//   s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
//   s21_decimal val2 = {{0, 0, 0, 0}};
//   s21_decimal res = {{0}};
//   ck_assert_int_eq(3, s21_div(val1, val2, &res));
// }
// END_TEST

// START_TEST(div_4) {
//   s21_decimal val1 = {{2, 0, 0, 0}};
//   s21_decimal val2 = {{0, 0, 0, 0}};
//   s21_decimal res = {{0}};
//   ck_assert_int_eq(3, s21_div(val1, val2, &res));
// }
// END_TEST

// START_TEST(div_5) {
//   s21_decimal value_1 = {{3500, 0, 0, 0}};
//   s21_decimal value_2 = {{5, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{7000, 0, 0, 0}};
//   set_degree(&value_1, 1);
//   set_degree(&value_2, 2);
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(div_6) {
//   s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
//   s21_decimal value_2 = {{0x2, 0, 0, 0}};
//   set_minos(&value_2);
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
//   set_minos(&check);
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(div_7) {
//   s21_decimal value_1 = {{1000, 0, 0, 0}};
//   s21_decimal value_2 = {{8, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{125, 0, 0, 0}};
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(div_8) {
//   s21_decimal value_1 = {{15, 0, 0, 0}};
//   set_minos(&value_1);
//   s21_decimal value_2 = {{0, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{0, 0, 0, 0}};
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 3);
// }
// END_TEST

// START_TEST(div_9) {
//   s21_decimal value_1 = {{1000, 0, 0, 0}};
//   s21_decimal value_2 = {{1, 0, 0, 0}};
//   set_degree(&value_2, 2);
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{100000, 0, 0, 0}};
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual1) {
//   // 792281625.14264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   int code = s21_div(decimal1, decimal2, NULL);

//   ck_assert_int_ne(code, 0);
// }

// START_TEST(test_div_fail_manual2) {
//   // степень 154 (показатель степени должен быть от 0 до 28)
//   // биты 0-15 не нули
//   // биты 24-30 не нули
//   s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual3) {
//   // степень 29 (показатель степени должен быть от 0 до 28)
//   s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual4) {
//   // степень 29 (показатель степени должен быть от 0 до 28)
//   s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual5) {
//   // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
//   s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual6) {
//   // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
//   s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual7) {
//   // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
//   s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual8) {
//   // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
//   s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual9) {
//   // Просто все единицы
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual10) {
//   // степень 154 (показатель степени должен быть от 0 до 28)
//   // биты 0-15 не нули
//   // биты 24-30 не нули
//   s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual11) {
//   // степень 29 (показатель степени должен быть от 0 до 28)
//   s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual12) {
//   // степень 29 (показатель степени должен быть от 0 до 28)
//   s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual13) {
//   // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
//   s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual14) {
//   // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
//   s21_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual15) {
//   // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
//   s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual16) {
//   // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
//   s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST

// START_TEST(test_div_fail_manual17) {
//   // Просто все единицы
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int code = s21_div(decimal1, decimal2, &result);

//   ck_assert_int_ne(code, 0);
// }
// END_TEST


// START_TEST(test_div_manual1) {
//   s21_decimal value_1, value_2, result = {{0, 0, 0, 0}};
//   // value_2 = 0.05;
//   // value_1 = -0.00035;

//   value_2.bits[0] = 0b00000000000000000000000000000101;
//   value_2.bits[1] = 0b00000000000000000000000000000000;
//   value_2.bits[2] = 0b00000000000000000000000000000000;
//   value_2.bits[3] = 0b00000000000000100000000000000000;
//   value_1.bits[0] = 0b00000000000000000000000000100011;
//   value_1.bits[1] = 0b00000000000000000000000000000000;
//   value_1.bits[2] = 0b00000000000000000000000000000000;
//   value_1.bits[3] = 0b10000000000001010000000000000000;

//   float check_float = 0;
//   int return_value = s21_div(value_1, value_2, &result);
//   s21_from_decimal_to_float(result, &check_float);
//   ck_assert_float_eq(check_float, -7e-3);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(test_div_manual2) {
//   s21_decimal value_1, value_2, result = {{0, 0, 0, 0}};
//   // value_2 = 0.30;
//   // value_1 = -0.00005;

//   value_2.bits[0] = 0b00000000000000000000000000011110;
//   value_2.bits[1] = 0b00000000000000000000000000000000;
//   value_2.bits[2] = 0b00000000000000000000000000000000;
//   value_2.bits[3] = 0b00000000000000100000000000000000;
//   value_1.bits[0] = 0b00000000000000000000000000000101;
//   value_1.bits[1] = 0b00000000000000000000000000000000;
//   value_1.bits[2] = 0b00000000000000000000000000000000;
//   value_1.bits[3] = 0b10000000000001010000000000000000;

//   float check_float = 0;
//   int return_value = s21_div(value_2, value_1, &result);
//   s21_from_decimal_to_float(result, &check_float);
//   ck_assert_float_eq(check_float, -6000);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

START_TEST(test_div_manual3) {
  s21_decimal value_1, value_2, result = {{0, 0, 0, 0}};
  float value1_float = s21_rand_r(-1e5, 1e5);
  float value2_float = s21_rand_r(-1e5, 1e5);

// printf("\nvaleu1: %f\n",value1_float);
// printf("\nvaleu2: %f\n",value2_float);

  s21_from_float_to_decimal(value1_float,&value_1);
  s21_from_float_to_decimal(value2_float,&value_2);
  // printf("\nvalue1: %u %u %u %u\n",value_1.bits[0],value_1.bits[1],value_1.bits[2],value_1.bits[3]);
  // printf("\nvalue2: %u %u %u %u\n",value_2.bits[0],value_2.bits[1],value_2.bits[2],value_2.bits[3]);
  float check_float = 0;
  int return_value = s21_div(value_1, value_2, &result);
  // printf("\nresult: %u %u %u %u\n",result.bits[0],result.bits[1],result.bits[2],result.bits[3]);
  s21_from_decimal_to_float(result, &check_float);
  ck_assert_float_eq(check_float, value1_float/value2_float);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *s21_div_suite(void) {
  Suite *test_suite = suite_create("s21_div_suite");
  TCase *test_case = tcase_create("s21_div_case");

  // tcase_add_test(test_case, div_0);
  // tcase_add_test(test_case, div_1);
  // tcase_add_test(test_case, div_2);
  // tcase_add_test(test_case, div_3);
  // tcase_add_test(test_case, div_4);
  // tcase_add_test(test_case, div_5);
  // tcase_add_test(test_case, div_6);
  // tcase_add_test(test_case, div_7);
  // tcase_add_test(test_case, div_8);
  // tcase_add_test(test_case, div_9);
  // tcase_add_test(test_case, test_div_fail_manual1);
  // tcase_add_test(test_case, test_div_fail_manual2);
  // tcase_add_test(test_case, test_div_fail_manual3);
  // tcase_add_test(test_case, test_div_fail_manual4);
  // tcase_add_test(test_case, test_div_fail_manual5);
  // tcase_add_test(test_case, test_div_fail_manual6);
  // tcase_add_test(test_case, test_div_fail_manual7);
  // tcase_add_test(test_case, test_div_fail_manual8);
  // tcase_add_test(test_case, test_div_fail_manual9);
  // tcase_add_test(test_case, test_div_fail_manual10);
  // tcase_add_test(test_case, test_div_fail_manual11);
  // tcase_add_test(test_case, test_div_fail_manual12);
  // tcase_add_test(test_case, test_div_fail_manual13);
  // tcase_add_test(test_case, test_div_fail_manual14);
  // tcase_add_test(test_case, test_div_fail_manual15);
  // tcase_add_test(test_case, test_div_fail_manual16);
  // tcase_add_test(test_case, test_div_fail_manual17);
  // tcase_add_test(test_case, test_div_manual1);
  // tcase_add_test(test_case, test_div_manual2);
  tcase_add_loop_test(test_case, test_div_manual3,0,5);

  suite_add_tcase(test_suite, test_case);
  return test_suite;
}
