#include "s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result=0;
  if(check_zero_decimal(value_1)&&check_zero_decimal(value_2)){
    result=0;
  }
  else{
  if(getBit(value_1,127)&&!getBit(value_2,127)){
  
  }
  else if(!getBit(value_1,127)&&getBit(value_2,127)){
  result=1;
  }
   else{
  s21_big_decimal current_value_1 = {0};
  s21_big_decimal current_value_2 = {0};
  // s21_big_decimal big_result = {0};
  big_initialization(value_1, &current_value_1);
  big_initialization(value_2, &current_value_2);
  normalization(&current_value_1, &current_value_2);
  if(!getBit(value_1,127)&&!getBit(value_2,127)){
  result=mantis_is_greater(current_value_1, current_value_2);
  }else{
    result=mantis_is_less(current_value_1, current_value_2);
  }
  }
  }
  return result;
}