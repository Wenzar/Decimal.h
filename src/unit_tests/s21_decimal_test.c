#include "s21_decimal_test.h"

int main(void) {
  Suite *list_testcases[] = {
                             s21_add_suite(),
                            //  s21_div_suite(),
                             s21_mul_suite(),
                             s21_sub_suite(),
                             s21_is_equal_suite(),
                             s21_floor_suite(),
                             s21_round_suite(),
                             s21_from_decimal_to_float_suite(),
                             s21_suite_from_decimal_to_int(),
                             s21_suite_from_int_to_decimal(),
                             s21_from_float_to_decimal_test(),
                             s21_suite_is_greater_or_equal(),
                             s21_suite_is_greater(),
                             s21_suite_is_less_or_equal(),
                             s21_suite_is_less(),
                             s21_suite_is_not_equal(),
                             s21_suite_truncate(),
                             s21_suite_negate(),
                             NULL};
  for (Suite **testcase = list_testcases; *testcase != NULL; testcase++) {
    run_testcase(*testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  static int testcase_count = 1;

  if (testcase_count > 0) {
    putchar('\n');
  }
  printf("%s%d%s", "TEST №", testcase_count, "\n");
  testcase_count++;
  SRunner *suiteRun = srunner_create(testcase);

  srunner_set_fork_status(suiteRun, CK_NOFORK);
  srunner_run_all(suiteRun, CK_NORMAL);

  srunner_free(suiteRun);
}