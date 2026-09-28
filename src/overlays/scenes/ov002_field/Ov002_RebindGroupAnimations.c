typedef unsigned short u16;

/* The resource group the track id resolves to: a count and a vector of
 * entries. Same shape Ov002_ElementRefreshNamedBindings walks. */
typedef struct {
    u16 wPad;                       /* +0x00 */
    u16 wCount;                     /* +0x02 */
    void **apEntry;                 /* +0x04 */
} Ov002EntryGroup;

extern Ov002EntryGroup *GetTrackEntryBase(int nId);
/* Hands back the next binding of the entry that matches, walking the cursor
   the caller passes; zero once there are no more. */
extern void *Ov002_FindNamedEntryFrom(void *pEntry, void *pName, void *pFilter,
                                 int *pCursor);
extern void RoomMesh_ForEachPrimOnPoint(void *pEntry, int nKind, void *pFound, void *pfn,
                          int bFlag);
extern void Ov002_SetWidgetHidden(void);

/* Re-apply every matching animation binding across a whole track group.
 *
 * Where Ov002_ElementRefreshNamedBindings re-registers one element's single named binding,
 * this walks each entry of the group and keeps asking for the next match until
 * the entry runs out, re-registering kinds 2 and 1 for each one with the same
 * callback and the caller's direction flag.
 */
void Ov002_RebindGroupAnimations(void *pName, void *pFilter, int bFlag, int nId)
{
    void *pEntry;
    void *pFound;
    int i;
    Ov002EntryGroup *pGroup;
    int nCursor;

    pGroup = GetTrackEntryBase((u16)nId);
    for (i = 0; i < (int)pGroup->wCount; i++) {
        pEntry = pGroup->apEntry[i];
        nCursor = 0;
        for (;;) {
            pFound = Ov002_FindNamedEntryFrom(pEntry, pName, pFilter, &nCursor);
            if (pFound == 0) {
                break;
            }
            RoomMesh_ForEachPrimOnPoint(pEntry, 2, pFound, (void *)Ov002_SetWidgetHidden,
                          bFlag);
            RoomMesh_ForEachPrimOnPoint(pEntry, 1, pFound, (void *)Ov002_SetWidgetHidden,
                          bFlag);
            nCursor++;
        }
    }
}
