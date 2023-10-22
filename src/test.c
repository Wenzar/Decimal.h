#include "s21_decimal.h"
#include "s21_div.c"
#include "s21_HELP_FUNCTIONS.c"
#include "s21_is_equal.c"
#include "s21_float_convertors.c"


int main (){
  float value1_float = s21_rand_r(-1e5, 1e5);
  float value2_float = s21_rand_r(-1e5, 1e5);
  printf("%f %f\n", value1_float, value2_float);
 s21_decimal value_1, value_2, result = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(value1_float,&value_1);
  s21_from_float_to_decimal(value2_float,&value_2);
    int error=0;
    error=s21_div(value_1, value_2, &result);
    printf("\nscale=%u sign=%u %u %u %u\n", small_find_out_the_degree(value_1), value_1.bits[3]>>31, value_1.bits[2], value_1.bits[1],value_1.bits[0]);
    printf("\nscale=%u sign=%u %u %u %u\n", small_find_out_the_degree(value_2), value_2.bits[3]>>31, value_2.bits[2], value_2.bits[1],value_2.bits[0]);
    printf("\nscale=%u sign=%u %u %u %u\n", small_find_out_the_degree(result), result.bits[3]>>31, result.bits[2], result.bits[1],result.bits[0]);
    float check_float = 0;
    s21_from_decimal_to_float(result, &check_float);
    printf("%f\n%f\n%d", check_float,value1_float/value2_float,error);
    return 0;
}