extern int Ov002_SetGaugeValue();

int Ov002_SetGaugeValueDefault(int a, int b, int c) {
    return Ov002_SetGaugeValue(a, b, c, 1, 0);
}
