#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if(dst!=NULL){
  if (src < 0) {
    src = -src;
    //добавляем минус
    dst->bits[3] = 0b10000000000000000000000000000000;
  }
  dst->bits[0] = src;
  }
  else{
    error=1;
  }

  return error;
}
