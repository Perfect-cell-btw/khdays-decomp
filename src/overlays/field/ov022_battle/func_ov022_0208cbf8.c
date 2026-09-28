/* Steps the current sub-object's animation and, when it ends, binds its idle block and sets state
 * 2. */

extern int Sequence_UpdateTracks(unsigned short *arg0, int arg1);
extern void Ov022_BindBlockAnimations(int arg0, int arg1, unsigned short *arg2, int arg3);

int func_ov022_0208cbf8(int arg0, int arg1) {
    int e = *(int *)(arg0 + *(int *)(arg0 + 0xc) * 4 + 0x18);
    if (Sequence_UpdateTracks((unsigned short *)(e + 8), arg1) != 0) {
        Ov022_BindBlockAnimations(arg0, *(int *)(arg0 + 0x54) + 4, (unsigned short *)(e + 8), 1);
        *(int *)(e + 0x11c) = 0;
        *(unsigned char *)(e + 0x118) = 2;
    }
    return 0;
}
