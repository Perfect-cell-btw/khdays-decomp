/* Show or hide the render node belonging to a key, and set its priority.
 *
 * The key maps to a slot; the slot's record is 0x18 bytes into the array at
 * +0x44 of the context, and its node pointer sits at +0xf4 of that record.
 * Showing writes a three-bit priority into bits 16 to 18 of the node's word at
 * +0xc; hiding calls the clearing counterpart and leaves the priority alone.
 *
 * The masked read must come first in the or: written the other way round mwcc
 * emits the shift pair ahead of the load.
 */

#include "game/enemy_common.h"

extern char *data_ov002_0207fa14;

extern int Ov002_FindKeyIndex(int nKey);

void Ov002_SetKeyNodeVisible(int nKey, int bVisible, int nValue) {
    char *root = data_ov002_0207fa14;
    int nIndex = Ov002_FindKeyIndex(nKey);

    if (bVisible != 0) {
        char *pNode = *(char **)(*(char **)(*(char **)(root + 0x44) +
                                            nIndex * 0x18) + 0xf4);

        *(unsigned int *)(pNode + 0xc) =
            (*(unsigned int *)(pNode + 0xc) & 0xfff8ffff) |
            ((unsigned int)(nValue & 7) << 16);
        Ov107_OrLowFlags(*(char **)(*(char **)(*(char **)(root + 0x44) +
                                                  nIndex * 0x18) + 0xf4),
                            1);
        return;
    }
    Ov107_TaskClearFlags(*(char **)(*(char **)(*(char **)(root + 0x44) +
                                              nIndex * 0x18) + 0xf4),
                        1);
}
