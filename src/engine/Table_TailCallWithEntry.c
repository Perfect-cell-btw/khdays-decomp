/* Indexes the table that lives 0xb44bc bytes into the block held by gSoundMgr and
 * tail-calls NNS_SndArcStrmStop with the element pointer.
 *
 * The second parameter is never touched here, but it must exist: it is forwarded to
 * NNS_SndArcStrmStop in r1, which is what keeps r1 out of the scratch pool and shifts the
 * pool/pointer temporaries up to r2/r3 exactly as the ROM does. */
extern char *gSoundMgr;
extern void *NNS_SndArcStrmStop();

void *Table_TailCallWithEntry(int i, int b) {
    return NNS_SndArcStrmStop((int *)(gSoundMgr + 0xb44bc) + i, b);
}
