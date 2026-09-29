/* Resolves a script actor operand: -1 is the event block's default actor (first word of the block
 * at +0x128), -3 and lower count from the local player (wrapping at four players), anything else is
 * returned as it is. */

extern unsigned short Session_GetLocalPlayerIndex();

int ScriptVm_ResolveActorIndex(int ctx, int index) {
    int r = index;
    if (index == -1) r = **(int **)(ctx + 0x128);
    if (index <= -3) {
        int t = (unsigned short)Session_GetLocalPlayerIndex();
        r = t + (-3 - index);
        if (r >= 4) r -= 4;
    }
    return r;
}
