/* Clear bit 0 of the +8 status byte of *(obj+0x38c), then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
struct b8 { unsigned int f : 8; };
extern int Ov238_RecoverTick(int);
void Ov238_AiEnterRecover(int param_1) {
    int p = *(int *)(*(int *)(*(int *)(param_1 + 4)) + 0x38c);
    ((struct b8 *)(p + 8))->f &= ~1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_RecoverTick);
}
