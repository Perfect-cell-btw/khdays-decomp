/* Resolves a player index: -1 is the default index from the object, and -3 and lower are counted
 * from the local player (wrapping at four players). */

extern unsigned short Session_GetLocalPlayerIndex();

int func_02020d10(int arg0, int arg1) {
    int r = arg1;
    if (arg1 == -1) r = **(int **)(arg0 + 0x128);
    if (arg1 <= -3) {
        int t = (unsigned short)Session_GetLocalPlayerIndex();
        r = t + (-3 - arg1);
        if (r >= 4) r -= 4;
    }
    return r;
}
