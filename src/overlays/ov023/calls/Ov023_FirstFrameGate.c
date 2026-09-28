/* Ov023_FirstFrameGate -- ov023 first-frame gate: do nothing while bit 0 of the heap status
 * halfword is set; otherwise ask Ov023_ScriptTestStatusBit3 whether the scene is ready and, if so, raise
 * bit 4. Always reports 0. The bit-0 test is SIGNED `> 0`, which is what the ROM's `movgt` shows. */
extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov023_ScriptTestStatusBit3(void);

int Ov023_FirstFrameGate(void) {
    unsigned short *h = (unsigned short *)NNSi_FndGetCurrentRootHeap();
    if ((*h & 1) > 0) {
        return 0;
    }
    if (Ov023_ScriptTestStatusBit3() != 0) {
        *h |= 0x10;
    }
    return 0;
}
