#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int add_return = 0;
  if (result != NULL) {
    if (error_scale(value_1) || error_scale(value_2) ||
        small_find_out_the_degree(value_1) > 28 ||
        small_find_out_the_degree(value_2) > 28) {
      add_return = 3;
    } else {
      if (!value_2.bits[0] && !value_2.bits[1] && !value_2.bits[2]) {
        add_return = 3;
      }
      if (add_return != 3) {
        s21_big_decimal current_value_1 = {0};
        s21_big_decimal current_value_2 = {0};
        s21_big_decimal big_result = {0};
        big_initialization(value_1, &current_value_1);
        big_initialization(value_2, &current_value_2);
        normalization(&current_value_1, &current_value_2);

        if ((!big_getBit(current_value_1, 223) &&
             !big_getBit(current_value_2, 223)) ||
            (big_getBit(current_value_1, 223) &&
             big_getBit(current_value_2, 223))) {
          if (mantis_s21_is_equal(current_value_1, current_value_2)) {
            big_result = one_big_decimal;
            big_uninitilization(big_result, result);

          } else {
            s21_big_decimal tmp_decimal = current_value_1;

            while (find_out_the_degree(current_value_1) != 28 &&
                   !raise_scale(&tmp_decimal) &&
                   mantis_is_greater(current_value_2, current_value_1)) {
              raise_scale(&current_value_1);
              tmp_decimal = current_value_1;
            }

            division_by_integer(current_value_1, current_value_2, &big_result);

            add_return = bank_round(big_result, &big_result);
            big_uninitilization(big_result, result);
          }

          result->bits[3] = value_1.bits[3] - value_2.bits[3];

        } else if ((!big_getBit(current_value_1, 223) &&
                    big_getBit(current_value_2, 223)) ||
                   (big_getBit(current_value_1, 223) &&
                    !big_getBit(current_value_2, 223))) {
          if (mantis_s21_is_equal(current_value_1, current_value_2)) {
            big_result = one_big_decimal;
            big_setBit(&big_result, 223, 1);
            big_uninitilization(big_result, result);

          } else {
            s21_big_decimal tmp_decimal = current_value_1;

            while (find_out_the_degree(current_value_1) != 28 &&
                   !raise_scale(&tmp_decimal) &&
                   mantis_is_greater(current_value_2, current_value_1)) {
              raise_scale(&current_value_1);
              tmp_decimal = current_value_1;
            }
            division_by_integer(current_value_1, current_value_2, &big_result);
            add_return = bank_round(big_result, &big_result);
            big_setBit(&big_result, 223, 1);
            big_uninitilization(big_result, result);
          }
          // printf("\nvalue_2.bits[3]>>16: %u\n", (value_2.bits[3] << 1) >> 17);
          // printf("\nvalue_1.bits[3]>>16: %u\n", ((value_1.bits[3] << 1) >> 17));
          if ((value_2.bits[3] << 1) >> 17 > (value_1.bits[3] << 1) >> 17) {
            result->bits[3] = 0b10000000000000000000000000000000;
          } else {
            result->bits[3] =
                (((value_1.bits[3] << 1) >> 17) - ((value_2.bits[3] << 1) >> 17)
                 << 16);
            set_minos(result);
          }
        }
      }
    }
  } else {
    add_return = 3;
  }
  return add_return;
}