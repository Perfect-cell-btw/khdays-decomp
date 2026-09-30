/* Starts a sound effect sequence from the sound archive (on the default bank when none is given).
 */

extern char *gSoundMgr;
extern int NNS_SndArcPlayerStartSeqArc(void *ptr, int arg1, int arg2);

int PlaySound(int arg0, int arg1) {
    if (arg0 == 0) {
        arg0 = *(int *)(gSoundMgr + 0x9c);
    }

    return NNS_SndArcPlayerStartSeqArc(gSoundMgr + 0xb44c8, arg0, arg1);
}
