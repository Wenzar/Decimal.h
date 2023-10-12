#include "s21_decimal.h"
#include "s21_div.c"
#include "s21_HELP_FUNCTIONS.c"
#include <check.h>
#include <limits.h>
#include <stdio.h>
#include "s21_from_int_to_decimal.c"
int main(){
    int code=0;
  s21_decimal decimal1 = {2,0,0,25<<16};
  s21_decimal decimal2 = {100,0,0,25<<16};
  s21_decimal result={0};
int src=-INT_MAX;
  code=s21_from_int_to_decimal(src,NULL);
  printf("%d\n", code);
  printf("sign=%u, scale=%u, bits[2]=%u, bits[1]=%u bits[0]=%u", result.bits[3]>>31,small_find_out_the_degree(result),result.bits[2],result.bits[1],result.bits[0]);
    return 0;
}

//0b10000000000000000000000000000000