/* Checks the equipment grid against the inventory and removes equipped items beyond what the player
 * still owns. */

#include "nitro/types.h"

extern unsigned char *data_0204be18;

extern void NNS_FndInitList(void *list, int offset);
extern void *NNS_FndGetNextListObject(void *list, void *object);
extern void Ov004_InitRecordContext(void *state, void *callbacks);
extern void Ov004_BuildMenuGrid(void *state, void *work, void *list, u16 *ids);
extern void Ov004_RebuildViewAndCountCells(void *state, void *work, void *list);
extern u16 *Table_FindKey(int kind, unsigned int id);
extern void Ov004_RemoveLoadoutEntries(int id, int count);
extern void Ov004_ReleaseHandleGridAndList(void *state, void *work, void *list);
extern void func_ov004_0204ecec(void *state);

void Ov004_BuildMissionObjectLists(void) {
    char list[0xc];
    char work[0x1e0];
    char state[0x100];
    void *node;
    u16 *entry;
    int remaining;

    NNS_FndInitList(list, 0x28);
    Ov004_InitRecordContext(state, 0);
    Ov004_BuildMenuGrid(state, work, list, (u16 *)(data_0204be18 + 0xee0));
    Ov004_RebuildViewAndCountCells(state, work, list);

    for (node = NNS_FndGetNextListObject(state + 0x20, 0); node != 0;
         node = NNS_FndGetNextListObject(state + 0x20, node)) {
        if (*(int *)node >= 2 && *(int *)node <= 11) {
            entry = Table_FindKey(0, *(int *)node);
            if (entry == 0) {
                remaining = *(int *)((char *)node + 4);
            } else {
                remaining = *(int *)((char *)node + 4) - (short)entry[1];
            }
            if (remaining > 0) {
                Ov004_RemoveLoadoutEntries(*(int *)node, remaining);
            }
        }
    }

    Ov004_ReleaseHandleGridAndList(state, work, list);
    func_ov004_0204ecec(state);
}
