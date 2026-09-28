/*
 * Ov002_SceneSpawnPanelRowCount - hand the head of the pending queue to one of
 * the ten counter rows.
 *
 * Rows are only handed out on a fixed interval, so the call does nothing until
 * enough ticks have passed since the last one. The row then gets its pair of
 * tweens started - the slide that carries it up and the fade that takes it out
 * - the palette that says whether the number is a gain or a loss, and the value
 * and its sign. The pending queue is shifted down over the entry just consumed,
 * the interval is re-armed from this tick, the row is marked busy and the
 * pending count drops by one.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    int nMode;
    int nDuration;
    int nFrom;
    int nTo;
    int aStart[2];
    unsigned int dwFlags;
} Ov002Tween;

typedef struct {
    int pad000[21];
    int aQueueSign[10];
    int aRowSign[10];
    int aRowBusy[10];
    char pad0cc[0xa10];
    u16 aRowPalette[10];
    char padaf0[0x38];
    Ov002Tween aRowSlide[10];
    Ov002Tween aRowFade[10];
    char padd58[0x10];
    int aQueueValue[10];
    int aRowValue[10];
    int nPending;
    char paddbc[0x280];
    u64 llStamp;
    u64 llInterval;
} Ov002RowScene;

extern int data_ov002_0207f628;

extern u64 OS_GetTick(void);
extern void Tween_Configure(Ov002Tween *pTween, int nMode, int nFrom, int nTo,
                          int nDuration);
extern void Tween_Start(Ov002Tween *pTween);

void Ov002_SceneSpawnPanelRowCount(int nValue, int nSign, int nRow)
{
    int i;
    Ov002RowScene *s;

    s = *(Ov002RowScene **)&data_ov002_0207f628;
    if (OS_GetTick() - s->llStamp < s->llInterval) {
        return;
    }

    Tween_Configure(&s->aRowSlide[nRow], 0, 0, 0xbb8000, 1000);
    Tween_Start(&s->aRowSlide[nRow]);
    Tween_Configure(&s->aRowFade[nRow], 0, 0x1f000, 0, 1000);
    Tween_Start(&s->aRowFade[nRow]);

    s->aRowPalette[nRow] = (nSign != 0) ? 0x7fc0 : 0x7fff;
    s->aRowValue[nRow] = nValue;
    s->aRowSign[nRow] = nSign;

    for (i = 0; i < 9; i++) {
        s->aQueueValue[i] = s->aQueueValue[i + 1];
        s->aQueueSign[i] = s->aQueueSign[i + 1];
    }

    s->llInterval = 0x3fec4;
    s->aRowBusy[nRow] = 1;
    s->llStamp = OS_GetTick();
    s->nPending--;
}
