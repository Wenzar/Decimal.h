#include <stdio.h>
#include "s21_add.c"
#include "s21_decimal.h"
#include <limits.h>
#include "s21_HELP_FUNCTIONS.c"
#include "s21_sub.c"
#include <check.h>
#include "s21_from_float_to_decimal.c"
#include "s21_from_decimal_to_float.c"
int main(){
   s21_decimal src1={0};
   float src=202.098;
   s21_from_float_to_decimal(src,&src1);
   printf("\nDEC1 sign:%u scale:%u %u %u %u\n",src1.bits[3]>>31, small_find_out_the_degree(src1),src1.bits[2],src1.bits[1],src1.bits[0]);
    return 0;
}