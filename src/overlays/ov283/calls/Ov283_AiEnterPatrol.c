/* Kick anim (0, phase 1), set +0x5c/+0x48, clear +0x78, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov283_PatrolIdleStep(int);
void Ov283_AiEnterPatrol(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0, 1);
    *(int *)(owner + 0x5c) = 0x900;
    *(int *)(owner + 0x48) = 0x27d8;
    *(int *)(owner + 0x78) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov283_PatrolIdleStep);
}
