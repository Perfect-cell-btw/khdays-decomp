/* Starts a sound effect sequence from the sound archive unless the same sound was just played
 * (recent-sound ring). */

extern unsigned char *gSoundMgr;
extern int RecentRing_Record(void *ptr, int arg);
extern void NNS_SndArcPlayerStartSeqArc(void *ptr, void *arg1, int arg2);

void PlaySoundChecked(void *ptr, int arg) {
    if (ptr == 0) {
        ptr = *(void **)(gSoundMgr + 0x9c);
    }

    if (RecentRing_Record(ptr, arg) == 0) {
        return;
    }

    NNS_SndArcPlayerStartSeqArc(gSoundMgr + 0xb44c8, ptr, arg);
}
