#include "s21_decimal.h"
#include "s21_div.c"
#include "s21_HELP_FUNCTIONS.c"
#include "s21_is_equal.c"


int main (){

  s21_decimal val1 = {{1000, 0, 0, 0}};
  s21_decimal val2 = {{1, 0, 0, 2<<16}};
  s21_decimal res = {0};
  s21_decimal check={{7000, 0, 0, 0}};
    int error=0;
    set_degree(&res,12);
    printf("\n%d\n", small_find_out_the_degree(res));

    error=s21_div(val1,val2,&res);
     printf("scale1=%u, scale2=%u\n", small_find_out_the_degree(val1),small_find_out_the_degree(val2));
    printf("%u error=%d, scale=%u, %u , %u , %u",res.bits[3], error, small_find_out_the_degree(res),res.bits[0],res.bits[1],res.bits[2]);
    printf("\n%d", s21_is_equal(res,check));
    return 0;
}