/* Ov002_UpdateLocalPeerReadyNotice (ARM).
 * The boolean conversion before the slot-bit test is present in the ROM.
 */

#include "game/engine.h"

typedef struct Ov002RootContext {
    char pad0000[0x8c8b];
    unsigned char bPeerReadyMask;
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;
extern int Ov002_IsSessionOpen(void);
extern int Ov022_GetEntryField66(int nSlot);
extern int func_ov022_020886d0(int nSlot);
extern int Ov002_GetSlotTableByte(int nSlot);
extern int Ov002_GetWidgetStateByte(int nWidget);
extern int Ov002_SetWidgetStateByte(int nWidget, int nState, int bRelayout);
extern signed char Ov002_GetCtxModeByte(void);
extern void Ov002_ReportRequestLevel(int nFlags, int nLevel, int nReserved);

void Ov002_UpdateLocalPeerReadyNotice(unsigned int nSlot, int bReady)
{
    Ov002RootContext *pRoot = data_ov002_0207fa00;
    int nWidget;
    int nLevel;
    if (nSlot != QueryActiveStateOrDelegate())
        return;
    if (bReady == 1) {
        if ((pRoot->bPeerReadyMask != 0) & (1 << nSlot))
            return;
        pRoot->bPeerReadyMask |= 1 << nSlot;
        if (!Ov002_IsSessionOpen())
            return;
        nLevel = 0;
        nWidget = Ov022_GetEntryField66(nSlot);
        if (nWidget >= 0) {
            nWidget = Ov002_GetSlotTableByte(nWidget);
            if (nWidget >= 0)
                nLevel = Ov002_GetWidgetStateByte(nWidget);
        }
        Ov002_ReportRequestLevel(Ov002_GetCtxModeByte(), nLevel, 0);
    } else {
        if ((pRoot->bPeerReadyMask == 0) & (1 << nSlot))
            return;
        pRoot->bPeerReadyMask &= ~(1 << nSlot);
        if (!Ov002_IsSessionOpen())
            return;
        nWidget = Ov002_GetSlotTableByte(Ov022_GetEntryField66(QueryActiveStateOrDelegate()));
        if (func_ov022_020886d0(QueryActiveStateOrDelegate()))
            return;
        Ov002_SetWidgetStateByte(nWidget, Ov002_GetWidgetStateByte(nWidget), 1);
    }
}
