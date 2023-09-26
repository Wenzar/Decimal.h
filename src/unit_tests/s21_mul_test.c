#include "s21_decimal_test.h"

START_TEST(mul_0)
{
    s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1)
{
    s21_decimal val1 = {{2, 0, 0, 0}};
    s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res;
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2)
{
    s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3)
{
    s21_decimal val1 = {{2, 0, 0, 0}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4)
{
    s21_decimal val1 = {{8, 0, 0, 0}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5)
{
    s21_decimal val1 = {{2, 0, 0, 0}};
    s21_decimal val2 = {{8, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6)
{
    s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7)
{
    s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{8, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8)
{
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9)
{
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(2, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_10)
{
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11)
{
    s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{0, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

Suite *s21_mul_suite(void)
{
    Suite *test_suite = suite_create("s21_mul_suite");
    TCase *test_case = tcase_create("s21_mul_case");

    tcase_add_test(test_case, mul_0);
    tcase_add_test(test_case, mul_1);
    tcase_add_test(test_case, mul_2);
    tcase_add_test(test_case, mul_3);
    tcase_add_test(test_case, mul_4);
    tcase_add_test(test_case, mul_5);
    tcase_add_test(test_case, mul_6);
    tcase_add_test(test_case, mul_7);
    tcase_add_test(test_case, mul_8);
    tcase_add_test(test_case, mul_9);
    tcase_add_test(test_case, mul_10);
    tcase_add_test(test_case, mul_11);

    suite_add_tcase(test_suite, test_case);
    return test_suite;
}