/* Reset the reaction slot (state -1, mark 1, clear hw60/1ae bits) then fan out three dispatches. */
extern int SetIndexedSlot(int, int, void *);
struct hw60 { unsigned short lo : 8, hi : 8; };
extern int Ov256_HelperMoveDispatch(int);
extern int Ov256_ArmEntry(int);
extern int Ov256_ClawWatchSlot(int);
void Ov256_Claw_AiStateInit(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0xc) = *(int *)owner + 0xb0;
    *(signed char *)(*(int *)owner + 0x1c6) = 1;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)owner + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov256_HelperMoveDispatch);
    SetIndexedSlot(param_1, 1, (void *)&Ov256_ArmEntry);
    SetIndexedSlot(param_1, 2, (void *)&Ov256_ClawWatchSlot);
}
