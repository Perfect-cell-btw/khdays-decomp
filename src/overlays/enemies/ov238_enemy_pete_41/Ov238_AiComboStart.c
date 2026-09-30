/* Reset +0x24/+0x2f; kick the base anim or the stepped anim depending on +0x20, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov238_ComboTick(int);
void Ov238_AiComboStart(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x24) = 0;
    *(signed char *)(owner + 0x2f) = 0;
    if (*(int *)(owner + 0x20) == 0) {
        Ov107_PostTagUpdate(*(int *)owner, 4, 0);
    } else {
        Ov107_PostTagUpdate(*(int *)owner, *(unsigned char *)(owner + 0x2d) + 8, 0);
        *(unsigned char *)(owner + 0x2d) += 1;
    }
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_ComboTick);
}
