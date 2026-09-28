/* Whether the actor is alive and has a pending object. */

int func_ov022_020ab350(int arg0) {
    if (*(unsigned short *)(arg0 + 0x12) == 0) return 0;
    return *(int *)(arg0 + 0x2668) != 0;
}
