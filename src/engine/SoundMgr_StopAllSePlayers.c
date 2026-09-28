/* Stops every sound-effect player (players 2 to 31). */

extern void NNS_SndPlayerStopSeqByPlayerNo(int index, int value);

void SoundMgr_StopAllSePlayers(void) {
    int index;

    for (index = 2; index < 0x20; index++) {
        NNS_SndPlayerStopSeqByPlayerNo(index, 0);
    }
}
