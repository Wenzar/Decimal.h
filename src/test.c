#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "s21_HELP_FUNCTIONS.c"
#include "s21_add.c"
#include "s21_decimal.h"
#include "s21_from_decimal_to_float.c"
#include "s21_from_float_to_decimal.c"
#include "s21_from_int_to_decimal.c"
#include "s21_sub.c"
#include "s21_from_decimal_to_int.c"

int main() {
//      s21_decimal src1 = {0};
//    src1.bits[0] = 0b01001100110100101000000111000101;
//   src1.bits[1] = 0b00000000000000000000000000000010;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000000000000000000000;
//     s21_decimal src2 = {0};
//   src2.bits[0] = 0b00000000000000000000000000000011;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal origin = {{0, 0, 0, 0}};
//    origin.bits[0] = 0b01001100110100101000000111000010;
//   origin.bits[1] = 0b00000000000000000000000000000010;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
 s21_decimal src1={0};
  s21_decimal src2={0};
  int tmp1 = -214748347;
  int tmp2 = 217483647;
  int res_s21 = 0;
  int res1 = -214748347 - 217483647;
  s21_from_int_to_decimal(tmp1, &src1);
  s21_from_int_to_decimal(tmp2, &src2);
   s21_decimal res = {{0}};
  int error=0;
  error= s21_sub(src1, src2, &res);
   s21_from_decimal_to_int(res, &res_s21);
  printf("\nERROR=%d\n", error);

  printf("\nDEC1 sign:%u scale:%u %u %u %u\n", src1.bits[3] >> 31,
         small_find_out_the_degree(src1), src1.bits[2], src1.bits[1],
         src1.bits[0]);
  printf("\nDEC2 sign:%u scale:%u %u %u %u\n", src2.bits[3] >> 31,
         small_find_out_the_degree(src2), src2.bits[2], src2.bits[1],
         src2.bits[0]);
  printf("\nRESULT %u %u %u %u %u\n", res.bits[3] >> 31,
         small_find_out_the_degree(res), res.bits[2], res.bits[1], res.bits[0]);
         printf("\n s21=%u origin_res=%u\n",res_s21,res1 );
       //   printf("\nORIGIN %u %u %u %u %u\n", origin.bits[3] >> 31,
       //   small_find_out_the_degree(origin), origin.bits[2], origin.bits[1], origin.bits[0]);

  return 0;
}