/* Tail-call the shared handler, zeroing the arg when the +0x1ac busy bit is set. */
extern int Ov107_ProcessObjectTick(int, int);
int Ov277_TickUnlessFrozen(int param_1, int param_2) {
    if (*(unsigned short *)(param_1 + 0x1ac) & 2) param_2 = 0;
    return Ov107_ProcessObjectTick(param_1, param_2);
}
