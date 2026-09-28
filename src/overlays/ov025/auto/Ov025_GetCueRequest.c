/* Return the address of the three-word cue request block at +0x9740 of the ov008 context. */

extern int data_ov025_020b5744;

int Ov025_GetCueRequest(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x9740;
}
