extern int Session_GetLocalPlayerIndex(void);
extern int Slot_EvalPackedParam(int a, int b);

void Ov022_AdvanceComboGauge(int obj, int param2, int param3) {
    unsigned char *p = (unsigned char *)(obj + 0x2aa4);
    int r5;
    if (Session_GetLocalPlayerIndex() != 0) return;
    if ((*(unsigned long long *)obj & 0x10000LL) != 0) return;
    if (p[0x10] == 0 && param2 == 0) return;
    switch (param2) {
    case 0:
        r5 = 2;
        break;
    case 1:
        r5 = 5;
        if (param3 > 0) p[0xf]++;
        break;
    case 2:
        r5 = 5;
        p[0xf]++;
        break;
    }
    if (Slot_EvalPackedParam(*(unsigned char *)(obj + 9), 0x4f) > 0) r5++;
    if (p[0xf] >= 0xf) p[0xf] = 2;
    if (p[0x10] != 2 && p[0x10] != 3 && p[0x10] != 4) {
        p[0x10] = 1;
        p[0x11] += r5;
        if (p[0xf] >= 0xb) {
            p[0x11] = 10;
            p[0x10] = 2;
        }
    }
}
