#include "s21_decimal_test.h"

START_TEST(test1) {
int x=5;
int y=5;
ck_assert_int_eq(x, y);
}
END_TEST



Suite *s21_add_suite(void) {
  Suite *test_suite = suite_create("s21_add_suite");
  TCase *test_case = tcase_create("s21_add_case");

    tcase_add_test(test_case, test1);

    suite_add_tcase(test_suite, test_case);
  return test_suite;
}