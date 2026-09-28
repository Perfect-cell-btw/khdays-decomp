/* Sets or clears bit 3 of the dispatcher's flags. */

void Ov022_SetBit3OnPtr20(int arg0, int arg1) {
    unsigned int *p = *(unsigned int **)(arg0 + 0x20);
    if (arg1 != 0) *p = *p | 8;
    else *p = *p & 0xfffffff7;
}
