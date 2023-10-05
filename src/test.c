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
#include "s21_is_equal.c"
#include "s21_floor.c"
#include "s21_round.c"
int main() {
     s21_decimal src1 = {0};
  src1.bits[0] = 0b10101111110010001101100101011111;
  src1.bits[1] = 0b01101000101000101011010010000001;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
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
//  s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000000000000000010100101; // -16.5
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000000010000000000000000;
   s21_decimal result={0};
//      result.bits[0] = 0b00000000000000000000000000010001;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
   s21_decimal res = {{0}};
   s21_decimal origin = {{0}};
    origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int error=0;
  error= s21_round(src1,&result);
  printf("\nERROR=%d\n", error);

  printf("\nDEC1 sign:%u scale:%u %u %u %u\n", src1.bits[3] >> 31,
         small_find_out_the_degree(src1), src1.bits[2], src1.bits[1],
         src1.bits[0]);
//   printf("\nDEC2 sign:%u scale:%u %u %u %u\n", src2.bits[3] >> 31,
//          small_find_out_the_degree(src2), src2.bits[2], src2.bits[1],
//          src2.bits[0]);
// printf("\nDEC2 sign:%u scale:%u %u %u %u\n", dec1.bits[3] >> 31,
//          small_find_out_the_degree(dec1), dec1.bits[2], dec1.bits[1],
//          dec1.bits[0]);
//   printf("\nRESULT %u %u %u %u %u\n", res.bits[3] >> 31,
//          small_find_out_the_degree(res), res.bits[2], res.bits[1], res.bits[0]);
       //   printf("\n s21=%u origin_res=%u\n",res_s21,res1 );
         printf("\nORIGIN %u %u %u %u %u\n", origin.bits[3] >> 31,
         small_find_out_the_degree(origin), origin.bits[2], origin.bits[1], origin.bits[0]);
       // printf("\n=== %lf", floor(0.99));
       printf("\nRESULT %u %u %u %u %u\n", result.bits[3] >> 31,
          small_find_out_the_degree(result), result.bits[2], result.bits[1], result.bits[0]);
          printf("\n%f", round(3.5) );

  return 0;
}