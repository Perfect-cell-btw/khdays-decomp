/* Number of decimal digits of a non-negative value (1 for 0). */

int Ov009_CountDecimalDigits(int arg0) {
    int count = 0;
    do {
        arg0 = arg0 / 10;
        count = count + 1;
    } while (arg0 > 0);
    return count;
}
