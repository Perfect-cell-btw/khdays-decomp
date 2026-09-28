#include "nitro/types.h"

/* The resource group the track id resolves to: a count and a vector of
 * entries. Same shape the matched EntityMgr_AttachTrackData walks. */
typedef struct {
    u16 wPad;                       /* +0x00 */
    u16 wCount;                     /* +0x02 */
    void **apEntry;                 /* +0x04 */
} Ov002EntryGroup;

extern int Ov002_GetCtxTableByte(int nSlot);
extern Ov002EntryGroup *GetTrackEntryBase(int nId);
extern void *FindEntryByExactName(void *pEntry, void *pName);
extern void RoomMesh_ForEachPrimOnPoint(void *pEntry, int nKind, void *pFound, void *pfn,
                          int bFlag);
extern void Ov002_SetWidgetHidden(void);

/* Re-apply the element's two named animation bindings.
 *
 * Does nothing for a nameless element. Otherwise it resolves the element's
 * slot to a track id, walks every entry of that id's group, looks the entry up
 * by the element's exact name and re-registers kinds 2 and 1 for it, each with
 * the same callback and the same direction flag - which is set unless the
 * element's last state bit was 1.
 */
void Ov002_ElementRefreshNamedBindings(char *pElement)
{
    /* The loop index is declared first: it is what the original gives
     * the lowest callee-saved register, and the rest follow from it. */
    int i;
    Ov002EntryGroup *pGroup;
    void *pEntry;
    void *pFound;
    int nId;

    if (*(signed char *)(pElement + 0x1a0) == 0) {
        return;
    }

    nId = Ov002_GetCtxTableByte(*(unsigned char *)(pElement + 0x10));
    if (nId < 0) {
        return;
    }

    pGroup = GetTrackEntryBase((u16)nId);
    i = 0;
    if ((int)pGroup->wCount <= 0) {
        return;
    }

    do {
        pEntry = pGroup->apEntry[i];
        pFound = FindEntryByExactName(pEntry, pElement + 0x1a0);
        RoomMesh_ForEachPrimOnPoint(pEntry, 2, pFound, (void *)Ov002_SetWidgetHidden,
                      *(unsigned char *)(pElement + 0x1c2) != 1);
        RoomMesh_ForEachPrimOnPoint(pEntry, 1, pFound, (void *)Ov002_SetWidgetHidden,
                      *(unsigned char *)(pElement + 0x1c2) != 1);
        i++;
    } while (i < (int)pGroup->wCount);
}
