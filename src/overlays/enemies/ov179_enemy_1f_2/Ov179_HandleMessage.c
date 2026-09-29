/* Message handler of the ov178 enemy (x3: ov178/179/180): a "spawned" message (kind 5, sub 0)
 * with no effect handle at +0x38c yet registers effect 0x143 (kind 4, enabled) on the +0xa0 node
 * and keeps the handle; then the base handler runs.
 * Two nested single-case switches: written as `if`s mwcc if-converts the sub-kind and handle
 * tests into predicated compares; the ROM branches on each (see Ov117_SpawnAuraOnTag5). */

#include "game/enemy_common.h"

extern void Ov107_AiState_OnMessage(int self, int msg, int c);

void Ov179_HandleMessage(int self, int msg, int c) {
    switch (*(unsigned char *)(msg + 2)) {
    case 5:
        switch (*(unsigned char *)(msg + 3)) {
        case 0:
            if (*(int *)(self + 0x38c) == 0) {
                *(int *)(self + 0x38c) = Ov107_CreateSpawnTask(self, 0x143, 4, 1, (void *)(self + 0xa0));
            }
            break;
        }
        break;
    }
    Ov107_AiState_OnMessage(self, msg, c);
}
