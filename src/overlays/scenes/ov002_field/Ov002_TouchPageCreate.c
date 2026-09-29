/*
 * Builds the map panel's touch page and hands back its poll loop.
 *
 * The slot context is taken from the heap, published to the overlay's own slot
 * and cleared, and its stroke list is initialised. Eight touch regions are then
 * registered, each with a resource id, a rectangle in panel coordinates and the
 * handler that runs while it is held: five narrow buttons along the bottom, a
 * wider one beside them, the drawing grid itself at forty across and a hundred
 * and sixty-eight down, and the palette strip on the left.
 *
 * The two regions whose sixth argument is not the empty id carry a second one,
 * used while the region is held rather than tapped.
 *
 * Finally the owning player is recorded, the page's resource is opened, the
 * panel is told to come up, and the poll loop is returned as the page's first
 * state.
 *
 * THUMB.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov002SlotContext {
    int hResource;
    int nSlot;
    char list[0x10];
    int aActive[4];
    int bFlag;
} Ov002SlotContext;

extern Ov002SlotContext *data_ov002_0207f99c;
extern int data_ov002_0207eeb0;

extern Ov002SlotContext *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *pDest, u8 nValue, u32 nSize);
extern void NNS_FndInitList(void *pList, u16 nOffset);
extern void Ov002_QueuePageCue(int nId, int nX, int nY, int nWidth, int nHeight,
                                int nHeldId, void *pHandler);
extern int InstantiateClass(int *pResource, int nArg);
extern void Ov002_LoadCueTable(void);

extern void Ov002_SetPageReady(void);
extern void Ov002_TouchPageCallback(void);
extern void Ov002_PublishSlotA1(void);
extern void Ov002_PublishSlotB0(void);
extern void Ov002_PublishSlotB1(void);
extern void Ov002_RecordMissionChoice(void);
extern void Ov002_MapTouchToCell(void);
extern void Ov002_AdvanceAlternatingPage(void);
extern void Ov002_PollPageTouches(void);

void *Ov002_TouchPageCreate(void)
{
    Ov002SlotContext *pCtx;

    pCtx = NNSi_FndGetCurrentRootHeap();
    data_ov002_0207f99c = pCtx;
    MI_CpuFill8(pCtx, 0, 0x2c);
    NNS_FndInitList(pCtx->list, 0x14);

    Ov002_QueuePageCue(0x4b3, 0, 0x60, 0x10, 0x30, 0xffff, Ov002_SetPageReady);
    Ov002_QueuePageCue(0x44c, 0x30, 0x90, 0x10, 0x10, 0xffff, Ov002_TouchPageCallback);
    Ov002_QueuePageCue(0x44d, 0x40, 0x90, 0x10, 0x10, 0xffff, Ov002_PublishSlotA1);
    Ov002_QueuePageCue(0x44e, 0x60, 0x90, 0x10, 0x10, 0xffff, Ov002_PublishSlotB0);
    Ov002_QueuePageCue(0x44f, 0x70, 0x90, 0x10, 0x10, 0xffff, Ov002_PublishSlotB1);
    Ov002_QueuePageCue(0x450, 0x90, 0x90, 0x40, 0x10, 0x464, Ov002_RecordMissionChoice);
    Ov002_QueuePageCue(0x474, 0x28, 0xa8, 0xb0, 0x18, 0xffff, Ov002_MapTouchToCell);
    Ov002_QueuePageCue(0x492, 0x18, 0xa0, 0x10, 0x17, 0x493, Ov002_AdvanceAlternatingPage);

    pCtx->nSlot = Session_GetLocalPlayerIndex();
    pCtx->hResource = InstantiateClass(&data_ov002_0207eeb0, 0);
    Ov002_LoadCueTable();
    return Ov002_PollPageTouches;
}
