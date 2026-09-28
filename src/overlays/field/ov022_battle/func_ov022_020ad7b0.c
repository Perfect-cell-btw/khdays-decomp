/* Whether the actor is at a quarter of its HP or less (unless it has ability 0x42). */

extern int Slot_EvalPackedParam(unsigned int arg0, int arg1);
int func_ov022_020ad7b0(int arg0) {
    int r = 0;
    int su = (int)((unsigned int)*(unsigned short *)(arg0 + 0x16) << 10);
    if (Slot_EvalPackedParam(*(unsigned char *)(arg0 + 9), 0x42) != 0) return r;
    if (*(unsigned short *)(arg0 + 0x12) <= (su >> 12)) r = 1;
    return r;
}
