#include "s21_decimal.h"

int last_bit(s21_decimal value);

int s21_from_float_to_decimal(float src, s21_decimal *dst)
{
    if (src < 0)
    {
        src = -src;
        setBit(dst, 127, 1);
    }
    int error = 0;
    int int_part = src;

    float x = 0;
    double copy_num = src;
    while (modff(copy_num, &x))
    {
        copy_num *= 10;
    }
    unsigned int remainder = copy_num;
    dst->bits[0] = remainder;
    int my_bit = 0;
    my_bit = last_bit(*dst);
    dst->bits[1] = int_part;
    //!!! првильно ли стоят скобки (32 - my_bit)?
    dst->bits[0] = dst->bits[0] << (32 - my_bit);
    while (dst->bits[1])
    {
        error = shift_right(dst, 1);
    }

    return error;
}

int last_bit(s21_decimal value)
{
    int bit = 0;
    for (int i = 0; i <= 95; i++)
    {
        int new_bit = 0;
        for (int j = i + 1; j <= 95; j++)
        {
            if (getBit(value, j))
            {
                new_bit = 1;
            }
        }
        if (new_bit == 0)
        {
            bit = i;
            break;
        }
    }
    return bit;
}