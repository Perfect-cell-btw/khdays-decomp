/* Sets slot flag 0 from the active word (+0x8e48) and clears slot flag 1; returns 0. */

extern int data_ov106_020b8b60;
extern void Ov002_SetSlotFlag1(int index, int flag);

int Ov106_ApplySlotFlags(void) {
    int active = *(int *)(data_ov106_020b8b60 + 0x8e48);

    Ov002_SetSlotFlag1(0, active == 0);
    Ov002_SetSlotFlag1(1, 0);
    return 0;
}
