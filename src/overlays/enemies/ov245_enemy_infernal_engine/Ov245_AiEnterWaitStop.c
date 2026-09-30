/* Run 020cce08 and 020d4810, set bit 1 of the +0x3b4 status byte, then dispatch. */
extern int SetIndexedSlot(int, int, void *);
struct b8 { unsigned int f : 8; };
extern int Ov245_SetNodeMode3(int);
extern int Ov245_Stop(int);
extern int Ov245_AiWaitStart(int);
void Ov245_AiEnterWaitStop(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov245_SetNodeMode3(*(int *)owner);
    Ov245_Stop(*(int *)(*(int *)owner + 0x438));
    ((struct b8 *)(*(int *)(*(int *)owner + 0x3b4) + 8))->f |= 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_AiWaitStart);
}
