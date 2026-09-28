/* Whether every flag of the offset-table row set for `key` is raised: the table is loaded, the
 * rows (0x14 apart, count in the set's +2) whose flag (+8 id plus nine) is clear are counted,
 * the count is reported through e700 (kind 1) and the table released; 1 when none is missing. */

#include "nitro/types.h"

extern void Ov002_LoadOffsetTableOnce(int nWhich);
extern char *Ov002_FindHandlerByKey(int nKey);
extern int GameState_IsFlagSet(int nFlag);
extern void Ov002_SetRootField85ac(int a, int count);
extern void Ov002_FreeRootBuffer0x8d7c(void);

int Ov069_AreKeyFlagsComplete(int key)
{
    int missing;
    char *rows;
    int i;
    char *row;

    missing = 0;
    Ov002_LoadOffsetTableOnce(0);
    rows = Ov002_FindHandlerByKey(key);
    if (rows != 0) {
        i = 0;
        if (*(s8 *)(rows + 2) > 0) {
            row = rows;
            do {
                if (GameState_IsFlagSet(*(s16 *)(row + 8) + 9) == 0) {
                    missing++;
                }
                i++;
                row += 0x14;
            } while (i < *(s8 *)(rows + 2));
        }
    }
    Ov002_SetRootField85ac(1, missing);
    Ov002_FreeRootBuffer0x8d7c();
    if (missing == 0) {
        return 1;
    }
    return 0;
}
