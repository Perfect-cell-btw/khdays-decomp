/* Clear the +0x38c gate byte and set bit 0 of the +0x3b4 status byte, then dispatch. */
extern int SetIndexedSlot(int, int, void *);
struct b8 { unsigned int f : 8; };
extern int Ov253_AiDropRollTimer(int);
void Ov253_AiEnterDrop(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(signed char *)(*(int *)(*(int *)owner + 0x38c) + 0xa8) = 0;
    ((struct b8 *)(*(int *)(*(int *)owner + 0x3b4) + 8))->f |= 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiDropRollTimer);
}
