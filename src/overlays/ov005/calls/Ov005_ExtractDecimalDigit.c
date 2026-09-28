/* Extract a decimal digit of the magnitude, starting at the units position. */
extern int Ov005_CountDecimalDigits(int);
extern int func_02020400(int numerator, int denominator);
int Ov005_ExtractDecimalDigit(int digitIndex, int value) {
    int divisor = 1;
    unsigned char index;
    if (value < 0) value *= -1;
    if (Ov005_CountDecimalDigits(value) < digitIndex + 1) return 0;
    for (index = 0; index < digitIndex; index++) divisor *= 10;
    divisor = func_02020400(value, divisor);
    divisor %= 10;
    return divisor;
}
