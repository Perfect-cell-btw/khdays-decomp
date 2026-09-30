/* Whether every entry of requirement list `idx` (0..2, the overlay's three id lists ending with
 * a non-positive id) is fulfilled: the record file is loaded (kind 0xe), each id looked up in it
 * and its value x 3 + 0x28e4 queried through 235d0 (kind 3) for a level of at least 2; the
 * file is freed on the way out of a complete walk. */

#include "nitro/types.h"

extern void *Archive_LoadFile(void *name, int mode);
extern int Ov069_LookupRecordValue(char *table, int id);
extern unsigned int GameState_GetField(int index, int kind);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern s16 *data_ov069_020baa20[];
extern char gOv069UiCmMslPath[];

int Ov069_RequirementListMet(unsigned int idx)
{
    char *buf;
    s16 *list;
    int id;

    if (idx >= 3) {
        return 0;
    }
    list = data_ov069_020baa20[idx];
    buf = Archive_LoadFile(gOv069UiCmMslPath, 0xe);
    if (buf != 0) {
        id = *list;
        while (id > 0) {
            if ((GameState_GetField(Ov069_LookupRecordValue(buf, id) * 3 + 0x28e4, 3) >= 2 ? 1 : 0) == 0) {
                return 0;
            }
            list++;
            id = *list;
        }
        NNSi_FndFreeFromDefaultHeap(buf);
    }
    return 1;
}
