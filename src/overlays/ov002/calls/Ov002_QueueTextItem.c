typedef unsigned short u16;

extern int Ov002_NewTextItem(int bSub, int nValue);
extern int Ov002_CreateHandlerRecord(u16 nA, u16 nB, short nC, u16 nD);
extern void Ov002_RegisterEventSlot(int nFlags, int nX, int nY, int nStyle, int nText);

/* Queue a text item, choosing how its body is built from the kind. The
 * sub-screen form carries the 0x1000 flag; unknown kinds are dropped.
 *
 * Each case takes its own pointer local: sharing one across the switch makes
 * mwcc hoist the argument load above the flag test, where the original reloads
 * it per case. The readiness flag is written as a ternary rather than an
 * equality for the same reason - it schedules the pointer load first.
 */
void Ov002_QueueTextItem(int bMain, int nFlags, int nX, int nY,
                         int nStyle, int nKind, const void *pParam)
{
    if (bMain == 0) {
        nFlags |= 1 << 12;
    }

    switch (nKind) {
    case 0:
        {
            const int *pWord = (const int *)pParam;

            Ov002_RegisterEventSlot(nFlags, nX, nY, nStyle,
                                Ov002_NewTextItem(bMain ? 0 : 1, *pWord));
        }
        break;

    case 1:
        {
            const char *pRec = (const char *)pParam;

            Ov002_RegisterEventSlot(nFlags, nX, nY, nStyle,
                                Ov002_CreateHandlerRecord(*(const u16 *)pRec,
                                                    *(const u16 *)(pRec + 2),
                                                    *(const short *)(pRec + 4),
                                                    *(const u16 *)(pRec + 6)));
        }
        break;
    }
}
