
#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst)
{
    //int sign = 1;
    int error = 0;
    if (src < 0)
    {
     //   sign = 0;
        src = -src;
    }
    dst->bits[0] = src;
    return error;
}