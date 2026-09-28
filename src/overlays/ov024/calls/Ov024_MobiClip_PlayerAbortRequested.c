/* Ov024_MobiClip_PlayerAbortRequested -- MobiClip player: has the user asked to abort playback?
 * True when either of the two request slots at heap+0x8bd8 / heap+0x8bdc reads 2. */
extern int NNSi_FndGetCurrentRootHeap(void);

int Ov024_MobiClip_PlayerAbortRequested(void) {
    int heap = NNSi_FndGetCurrentRootHeap();
    return *(int *)(heap + 0x8bd8) == 2 || *(int *)(heap + 0x8bdc) == 2;
}
