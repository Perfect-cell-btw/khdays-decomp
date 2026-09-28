/* Host only: steps the actor's overlay animation while it is flagged. */

extern short Session_GetLocalPlayerIndex(void);
extern void Sequence_UpdateTracks(unsigned short *arg0, int arg1);
void func_ov022_0209ca88(int arg0) {
    unsigned int *p;
    if (Session_GetLocalPlayerIndex() != 0) return;
    p = *(unsigned int **)(arg0 + 0x20);
    if ((*p & 0x40) == 0) return;
    Sequence_UpdateTracks((unsigned short *)(p + 1), *(short *)(arg0 + 0x2aba));
}
