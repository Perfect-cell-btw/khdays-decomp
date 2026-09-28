extern void Ov042_AdvanceArg1StateFrom0Or2();
extern void Ov022_SetAnimState();

void Ov042_SetAnimStateWithEnterHook(int self, int a) {
    int base = self + 0x2c;
    switch (a) {
    case 0x2f:
    case 0x30:
        if (a != *(int *)(self + 0x6bc)) Ov042_AdvanceArg1StateFrom0Or2(self, base + 0x2c00);
        break;
    }
    Ov022_SetAnimState(self, a);
}
