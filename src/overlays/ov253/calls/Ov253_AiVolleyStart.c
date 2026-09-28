/* Unless the child gate is set, clear +0x1c/+0x20, kick anim (3, phase 1), then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_VolleyTick(int);
void Ov253_AiVolleyStart(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4)) != 0) return;
    *(int *)(owner + 0x1c) = 0;
    *(int *)(owner + 0x20) = 0;
    Ov107_PostTagUpdate(*(int *)owner, 3, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_VolleyTick);
}
