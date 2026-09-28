extern int Ov022_IsIndexedRecordBit0Set(int a, int i);
extern void Ov022_SetSlotClaim(int a, int i, int one);

void func_ov022_0209c700(unsigned int *param_1) {
    int i = 0;
    char *p = (char *)param_1;
    do {
        if (*(char *)(p + 0xda9) != 0 && Ov022_IsIndexedRecordBit0Set((int)param_1, i) == 0) {
            Ov022_SetSlotClaim((int)param_1, i, 1);
        }
        i = i + 1;
        p = p + 0x164;
    } while (i < 2);
    *(unsigned long long *)param_1 |= 0x8000;
}
