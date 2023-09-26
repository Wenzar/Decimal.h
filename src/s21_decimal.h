#ifndef STRING_H
#define STRING_H

typedef struct {
  int bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Функция для инициализации s21_decimal
void initialize_s21_decimal(s21_decimal *dec, int sign, int exponent, int mantissa) {
    dec->bits[0] = mantissa & 0xFFFFFFFF;
    dec->bits[1] = (mantissa >> 32) & 0xFFFFFFFF;
    dec->bits[2] = (mantissa >> 64) & 0xFFFFFFFF;
    dec->bits[3] = (sign << 31) | ((exponent & 0xFF) << 16);
}


#endif