/* Node_FlipDoubleBuffer -- flip a node's double buffer: toggle the index at +0x1c and re-point +0x18 at
 * the matching 0xc-byte slot. Does nothing (and reports 0) unless AsyncMessage_Flush accepts the
 * current buffer.
 *
 * Parked as a "register-colouring tie" after seven source forms: the ROM colours the toggled
 * value r2 and the 0xc multiplier r1, mwcc shifts both down one because "r0 is free after the
 * guard call returns". r0 is NOT free -- the guard's result is this function's RETURN VALUE, so
 * it has to survive to the `pop`, and both exits hand it back (the early one via the `popeq` that
 * already has 0 in r0). Everything shifted down by exactly one register is the fingerprint of a
 * reserved r0; ask whether the function returns something before touching the body. Third park
 * closed on this axis (cf. Ov010_BindResourceHandle, func_ov022_020aeef8).
 */
extern int AsyncMessage_Flush(int *node);

int Node_FlipDoubleBuffer(int p) {
    unsigned int v;
    int ok = AsyncMessage_Flush(*(int **)(p + 0x18));
    if (ok == 0) {
        return ok;
    }
    v = *(unsigned int *)(p + 0x1c) ^ 1;
    *(unsigned int *)(p + 0x1c) = v;
    *(unsigned int *)(p + 0x18) = v * 0xc + p;
    return ok;
}
