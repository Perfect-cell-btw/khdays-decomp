/* Run 020d07f0 on the motion block; unless busy, mark state 3 and dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov238_TurnVelocity(int, int);
void Ov238_AiTurnUntilAnimEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov238_TurnVelocity(param_1, *(int *)(*(int *)owner + 0x3e0) + 0x2c);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = 3;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
