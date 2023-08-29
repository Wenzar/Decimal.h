#include "s21_decimal_test.h"

int main(void) {
  Suite *list_testcases[] = {s21_add_suite(),
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