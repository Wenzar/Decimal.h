#include "s21_HELP_FUNCTIONS.c"
#include "s21_add.c"
#include "s21_decimal.h"
#include "s21_from_decimal_to_float.c"
#include "s21_from_float_to_decimal.c"
#include "s21_from_int_to_decimal.c"
#include "s21_sub.c"
#include <check.h>
#include <limits.h>
#include <stdio.h>

int main() {
  //   s21_decimal src1 = {0};
  //   src1.bits[0] = 0b11111111111111111111111111111111;
  //   src1.bits[1] = 0b11111111111111111111111111111111;
  //   src1.bits[2] = 0b11111111111111111111111111111111;
  //   src1.bits[3] = 0b10000000000000000000000000000000;
  //   s21_decimal src2 = {0};
  //   src2.bits[0] = 0b00000000000000000000000000001010;
  //   src2.bits[1] = 0b00000000000000000000000000000000;
  //   src2.bits[2] = 0b00000000000000000000000000000000;
  //   src2.bits[3] = 0b00000000000000000000000000000000;
  // s21_decimal original_res = {0};
  //   original_res.bits[0] = 0b11111111111111111111111111111110;
  //   original_res.bits[1] = 0b11111111111111111111111111111111;
  //   original_res.bits[2] = 0b11111111111111111111111111111111;
  //   original_res.bits[3] = 0b10000000000000000000000000000000;
  // //   s21_decimal res = {0};
  //    s21_decimal src1 = {0};
  //   src1.bits[0] = 0b11111111111111111111111111111111;
  //   src1.bits[1] = 0b11111111111111111111111111111111;
  //   src1.bits[2] = 0b11111111111111111111111111111111;
  //   src1.bits[3] = 0b10000000000000000000000000000000;
  //   s21_decimal src2 = {0};
  //   src2.bits[0] = 0b00000000000000000000000000000010;
  //   src2.bits[1] = 0b00000000000000000000000000000000;
  //   src2.bits[2] = 0b00000000000000000000000000000000;
  //   src2.bits[3] = 0b00000000000000110000000000000000;
  //   s21_decimal res = {{0}};
  s21_decimal src1 = {0}, src2 = {0};
  float a = -1234;
  float b = -1.234;
  float res_our_dec = 0.0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  printf("\nDEC1 sign:%u scale:%u %u %u %u\n", src1.bits[3] >> 31,
         small_find_out_the_degree(src1), src1.bits[2], src1.bits[1],
         src1.bits[0]);
  printf("\nDEC2 sign:%u scale:%u %u %u %u\n", src2.bits[3] >> 31,
         small_find_out_the_degree(src2), src2.bits[2], src2.bits[1],
         src2.bits[0]);
  float res_origin = -1235.234;
  s21_decimal res = {0};
  s21_add(src1, src2, &res);
  s21_from_decimal_to_float(res, &res_our_dec);
  printf("\nORIGIN%f\n", res_origin);
  printf("\nMY%f\n", res_our_dec);

  //   printf("\n%d\n",s21_add(src1, src2, &res));

  //   printf("\nORIGINAL %u %u %u %u\n",
  //   original_res.bits[3]>>16,original_res.bits[2],original_res.bits[1],original_res.bits[0]);
  printf("\nRESULT %u %u %u %u %u\n", res.bits[3] >> 31,
         small_find_out_the_degree(res), res.bits[2], res.bits[1], res.bits[0]);

  return 0;
}