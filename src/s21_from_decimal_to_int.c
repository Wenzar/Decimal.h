#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  // printf("\n%d\n",small_find_out_the_degree(src));

  s21_big_decimal big_copy_decimal = {0};
  big_initialization(src, &big_copy_decimal);
  
  int sign = 1;
  if (big_getBit(big_copy_decimal, 223)) {
    big_setBit(&big_copy_decimal, 223, 0);
    sign = 0;
  }

  while ((big_copy_decimal.bits[6] >> 16) != 0) {
    error = demotion_scale(&big_copy_decimal);
  }
  if(error_scale(src)){
    error=1;
  }
  if (big_copy_decimal.bits[1] || big_copy_decimal.bits[2]) {
    error = 1;
  }
  if(big_copy_decimal.bits[0]> 2147483647){
  if (sign) {
    *dst = 2147483647;
  } else {
    *dst = -2147483648;
  }
  }
  else{
    if(sign){
      *dst=big_copy_decimal.bits[0];
    }
    else {
      *dst=-big_copy_decimal.bits[0];
    }
  }



  // if(!sign){
  //    *dst = -*dst;
  // }
  // printf("\nRESULT from_decimal_to_int %u %u %u %u \n", src.bits[3],
  //        src.bits[2], src.bits[1], src.bits[0]);

  return error;
}