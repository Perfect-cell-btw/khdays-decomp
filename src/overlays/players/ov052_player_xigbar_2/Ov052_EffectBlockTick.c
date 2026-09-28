/* Drives the ov032 enemy's effect block state machine (and its byte-identical twins). A
 * running block whose owner (+0x22f8) is no longer busy goes idle. State 1 waits for the
 * +0x7b0 timer to reach 0x1d000, then restarts sequences 0, 2 and 1 from zero and advances
 * to 2; states 2 and 4 poll the block against the +0x2aba rate, 4 ending in state 5 once
 * the poll reports done. */
typedef unsigned char u8;

extern int Ov022_IsState9Or6WithFlag200(void *p);
extern void Anim_SetFrameWrapped(void *p, int idx, int a);
extern unsigned int Sequence_UpdateTracks(void *p, int rate);

void Ov052_EffectBlockTick(int self, char *block)
{
    if (*(u8 *)(block + 0x114) != 0 && Ov022_IsState9Or6WithFlag200((void *)(self + 0x22f8)) == 0) {
        *(u8 *)(block + 0x114) = 0;
    }
    switch (*(u8 *)(block + 0x114)) {
    case 1:
        if (*(int *)(self + 0x7b0) < 0x1d000) {
            return;
        }
        Anim_SetFrameWrapped(block + 0xc, 0, 0);
        Anim_SetFrameWrapped(block + 0xc, 2, 0);
        Anim_SetFrameWrapped(block + 0xc, 1, 0);
        *(u8 *)(block + 0x114) = 2;
        return;
    case 2:
        Sequence_UpdateTracks(block + 0xc, *(short *)(self + 0x2aba));
        return;
    case 4:
        if (Sequence_UpdateTracks(block + 0xc, *(short *)(self + 0x2aba)) != 0) {
            *(u8 *)(block + 0x114) = 5;
        }
        return;
    }
}
