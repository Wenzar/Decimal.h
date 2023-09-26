#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result)
{
    int error = 0;

    s21_big_decimal big_copy_decimal = {0};
    big_initialization(value, &big_copy_decimal);
    while (find_out_the_degree(big_copy_decimal) != 0)
    {
        error = demotion_scale(&big_copy_decimal);
    }
    big_uninitilization(big_copy_decimal, result);
    return error;
}