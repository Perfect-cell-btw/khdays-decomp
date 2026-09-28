/* Clear the flag at *(*child+0x384)+0xa8, set *(*child)+0x54 = 0x3000 and register the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_ChargeInTick(int);
void Ov236_RidersA_AiEnterChargeIn(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(unsigned char *)(*(int *)(*(int *)child + 0x384) + 0xa8) = 0;
    *(int *)(*(int *)child + 0x54) = 0x3000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_ChargeInTick);
}
