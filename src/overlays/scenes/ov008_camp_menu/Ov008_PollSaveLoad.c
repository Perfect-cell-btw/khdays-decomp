/* Save file layout, confirmed against the write side (Ov008_CommitSaveToSlot):
 *   +0x00  magic 0xc8f592a6
 *   +0x04  SHA1 digest (0x14 bytes)
 *   +0x18  payload, 0x1cac bytes -- this IS the game state, and its +0x10 is the
 *          packed flag/bitfield store that GameState_IsFlagSet reads.
 * Block size on the card is 0x2018. */

#include "game/engine.h"

typedef struct {
    unsigned char blockCounter;
    unsigned char slot;
    unsigned char pad02[2];
    int resultCode;
    void *thread;
} CardTransferCtx;

extern int Ov008_ReapTerminatedJobResult(void);
extern int Ov008_VerifySha1Signature(void *buf);
extern void Ov008_StartCardThread(int a, int b, int c);

extern char *data_0204be14;
extern char *data_0204be18;
extern CardTransferCtx data_ov008_02090fb4;

int Ov008_PollSaveLoad(void) {
    int ret;
    int status;
    int *word;
    unsigned int i;

    status = Ov008_ReapTerminatedJobResult();
    if (status < 0) {
        goto out_busy;
    }
    if (status != 0) {
        ret = 3;
    } else {
        word = (int *)data_0204be14;
        for (i = 0; i < 8; i++) {
            if (*word++ != 0) {
                break;
            }
        }
        if (i == 8) {
            ret = 2;
        } else if (Ov008_VerifySha1Signature(data_0204be14) != 0) {
            ret = 0;
            data_0204be18 = data_0204be14 + 0x18;
        } else {
            data_ov008_02090fb4.blockCounter = data_ov008_02090fb4.blockCounter + 1;
            if (data_ov008_02090fb4.blockCounter >= 2) {
                ret = 4;
            } else {
                Ov008_StartCardThread(
                    (data_ov008_02090fb4.blockCounter
                     + data_ov008_02090fb4.slot * 2) * 0x2018 + 0x20,
                    (int)data_0204be14, 0x2018);
                return 1;
            }
        }
    }
    goto out_tail;
out_busy:
    return 1;
out_tail:
    Sleep_Unblock();
    return ret;
}
