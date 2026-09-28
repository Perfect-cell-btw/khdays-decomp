/* Resolve an item id to the resource the HUD should draw for it.
 *
 * A tracked slot answers with the entry the context holds at +0x94, indexed by
 * the slot and skipping the first word, falling back to the per-slot array at
 * +0x58 when that entry is null. An untracked id has no resource, except id
 * 0x18, which is drawn from the BG0 screen and answers with that pointer.
 *
 * The zero answer is written through a switch rather than an else: as a single
 * instruction in an if/else mwcc predicates it, and the ROM's separate block
 * disappears.
 */
extern char *data_ov002_0207f60c;

extern int Ov002_ItemIdToSlot(int nItemId);
extern int G2S_GetBG0ScrPtr(void);

int Ov002_GetItemResource(int nItemId) {
    int nResult;
    int nSlot = Ov002_ItemIdToSlot(nItemId);

    if (nSlot != -1) {
        char *root = data_ov002_0207f60c;

        nResult = *(int *)(*(int *)(root + 0x94) + nSlot * 4 + 4);
        if (nResult == 0) {
            nResult = *(int *)(root + nSlot * 4 + 0x58);
        }
    } else {
        switch (nItemId) {
        case 0x18:
            nResult = G2S_GetBG0ScrPtr();
            break;
        default:
            nResult = 0;
            break;
        }
    }
    return nResult;
}
