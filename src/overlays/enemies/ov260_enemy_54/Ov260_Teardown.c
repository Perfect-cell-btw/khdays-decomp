/* Teardown of the ov260 actor: outside move 6 the +0x49c and +0x4a4 effects are released from the
 * +0x3c task list, outside move 0xb the +0x4bc one too; then the base teardown runs (020c7ca4). */

#include "game/enemy_common.h"

extern void TaskList_FinishByTag(void *taskList, void *handle);

void Ov260_Teardown(char *self)
{
    if (*(signed char *)(self + 0x1c6) != 6) {
        if (*(void **)(self + 0x49c) != 0) {
            TaskList_FinishByTag(*(void **)(self + 0x3c), *(void **)(self + 0x49c));
            *(void **)(self + 0x49c) = 0;
        }
        if (*(void **)(self + 0x4a4) != 0) {
            TaskList_FinishByTag(*(void **)(self + 0x3c), *(void **)(self + 0x4a4));
            *(void **)(self + 0x4a4) = 0;
        }
    }
    if (*(signed char *)(self + 0x1c6) != 0xb && *(void **)(self + 0x4bc) != 0) {
        TaskList_FinishByTag(*(void **)(self + 0x3c), *(void **)(self + 0x4bc));
        *(void **)(self + 0x4bc) = 0;
    }
    Ov107_AiState_PostTickBase(self);
}
