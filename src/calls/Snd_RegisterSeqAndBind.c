/* Registers a sequence, stashes the handle at +0xc of the player block and hands the
 * translated handle to ModelAnimSet_Bind.
 *
 * The handle must be read BACK out of +0xc for the ResSlot_Acquire call rather than kept in
 * a local: bound to a local, mwcc defers the `mov r2,r0` until after the other three
 * argument moves. */
extern int SND_RegisterSeq(int c, int d);
extern int ResSlot_Acquire(int h, int flag);
extern void ModelAnimSet_Bind(int a, int b, int c, int d);

int Snd_RegisterSeqAndBind(int a, int b, int c, int d) {
    *(int *)(a + 0xc) = SND_RegisterSeq(c, d);
    ModelAnimSet_Bind(a, b, ResSlot_Acquire(*(int *)(a + 0xc), 1), d);
    return 1;
}
