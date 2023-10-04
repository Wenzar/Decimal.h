#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int add_return = 0;

  int fatal_error = check_error(value_1, value_2);
  if (!(fatal_error)) {
    s21_big_decimal current_value_1 = {0};
    s21_big_decimal current_value_2 = {0};
    s21_big_decimal big_result = {0};

    big_initialization(value_1, &current_value_1);
    big_initialization(value_2, &current_value_2);

    normalization(&current_value_1, &current_value_2);

    if (!big_getBit(current_value_1, 223) &&
        !big_getBit(current_value_2, 223)) {
      big_addition(current_value_1, current_value_2, &big_result);

      add_return = bank_round(big_result, &big_result);
      big_uninitilization(big_result, result);
    } else if (big_getBit(current_value_1, 223) &&
               big_getBit(current_value_2, 223)) {
      big_addition(current_value_1, current_value_2, &big_result);

      big_setBit(&big_result, 223, 1);
      add_return = bank_round(big_result, &big_result);
      if (add_return) {
        add_return = 2;
      }
      big_uninitilization(big_result, result);
    } else {
      if (mantis_is_greater(current_value_1, current_value_2)) {
        if (!big_getBit(current_value_1, 223) &&
            big_getBit(current_value_2, 223)) {
          difference(current_value_1, current_value_2, &big_result);
          add_return = bank_round(big_result, &big_result);

          big_uninitilization(big_result, result);
        } else if (big_getBit(current_value_1, 223) &&
                   !big_getBit(current_value_2, 223)) {
          difference(current_value_1, current_value_2, &big_result);
          // printf("\nRESULT HERE %u %u %u %u %u %u %u\n",
          // find_out_the_degree(big_result),big_result.bits[5],big_result.bits[4],big_result.bits[3],big_result.bits[2],big_result.bits[1],big_result.bits[0]);

          add_return = bank_round(big_result, &big_result);

          big_setBit(&big_result, 223, 1);
          if (add_return) {
            add_return = 2;
          }
          big_uninitilization(big_result, result);
        }
      } else if (mantis_is_greater(current_value_2, current_value_1)) {
        if (!big_getBit(current_value_1, 223) &&
            big_getBit(current_value_2, 223)) {
          difference(current_value_2, current_value_1, &big_result);

          big_setBit(&big_result, 223, 1);
          add_return = bank_round(big_result, &big_result);
          if (add_return) {
            add_return = 2;
          }
          big_uninitilization(big_result, result);
        } else if (big_getBit(current_value_1, 223) &&
                   !big_getBit(current_value_2, 223)) {
          difference(current_value_2, current_value_1, &big_result);
          add_return = bank_round(big_result, &big_result);

          big_uninitilization(big_result, result);
        }
      }
    }
  } else {
    add_return = 1;
  }
  return add_return;
}