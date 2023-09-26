#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst)
{
    int error = 0;
    int sign = 1;
    if (getBit(src, 127))
    {
        setBit(&src, 127, 0);
        sign = 0;
    }

    while ((src.bits[4] >> 16) != 0)
    {
        error = demotion_scale;
    }
    if (src.bits[1] || src.bits[2])
    {
        error = 1;
    }
    if (src.bits[0] > 2147483647 && sign)
    {
        *dst = 2147483647;
    }
    else if (src.bits[0] > 2147483647 && !sign)
    {
        *dst = -2147483646;
    }
    else
    {
        *dst = src.bits[0];
    }

    return error;
}