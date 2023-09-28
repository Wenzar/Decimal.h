#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    s21_big_decimal current_value_1 = {0};
    s21_big_decimal current_value_2 = {0};
    s21_big_decimal big_result = {0};

    big_initialization(value_1, &current_value_1);
    big_initialization(value_2, &current_value_2);
    normalization(&current_value_1, &current_value_2);
    int sub_return = 0;

    if (mantis_is_greater(current_value_1, current_value_2))
    {
        if (big_getBit(current_value_1, 223) && big_getBit(current_value_2, 223))
        {
            big_addition(current_value_1, current_value_2, &big_result);
            big_setBit(&big_result, 223, 1);
            sub_return = bank_round(big_result, &big_result);
            if(sub_return){
                sub_return=2;
            }
            big_uninitilization(big_result, result);
        }
        else if (!big_getBit(current_value_1, 223) && big_getBit(current_value_2, 223))
        {
            big_addition(current_value_1, current_value_2, &big_result);
            sub_return = bank_round(big_result, &big_result);
            big_uninitilization(big_result, result);
        }
        else if (big_getBit(current_value_1, 223) && !big_getBit(current_value_2, 223))
        {
            big_addition(current_value_1, current_value_2, &big_result);
            big_setBit(&big_result, 223, 1);
            sub_return = bank_round(big_result, &big_result);
            if(sub_return){
                sub_return=2;
            }
            big_uninitilization(big_result, result);
        }
        else if (!big_getBit(current_value_1, 223) && !big_getBit(current_value_2, 223))
        {
            difference(current_value_1, current_value_2, &big_result);
            sub_return = bank_round(big_result, &big_result);
            big_uninitilization(big_result, result);
        }
    }
    else if (mantis_is_greater(current_value_2, current_value_1))
    {
        if (big_getBit(current_value_1, 223) && big_getBit(current_value_2, 223))
        {
            difference(current_value_2, current_value_1, &big_result);
            sub_return = bank_round(big_result, &big_result);
            big_uninitilization(big_result, result);
        }
        else if (!big_getBit(current_value_1, 223) && big_getBit(current_value_2, 223))
        {
            big_addition(current_value_1, current_value_2, &big_result);
            sub_return = bank_round(big_result, &big_result);
            big_uninitilization(big_result, result);
        }
        else if (big_getBit(current_value_1, 223) && !big_getBit(current_value_2, 223))
        {
            big_addition(current_value_1, current_value_2, &big_result);
            big_setBit(&big_result, 223, 1);
            sub_return = bank_round(big_result, &big_result);
             if(sub_return){
                sub_return=2;
            }
            big_uninitilization(big_result, result);
        }
        else if (!big_getBit(current_value_1, 223) && !big_getBit(current_value_2, 223))
        {
            difference(current_value_2, current_value_1, &big_result);
            big_setBit(&big_result, 223, 1);
            sub_return = bank_round(big_result, &big_result);
             if(sub_return){
                sub_return=2;
            }
            big_uninitilization(big_result, result);
        }
    }
    else if (mantis_s21_is_equal(current_value_1, current_value_2))
    {
        *result = decimal_null;
    }
    return sub_return;
}
