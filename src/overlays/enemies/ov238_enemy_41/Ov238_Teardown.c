/* Teardown of the ov238 actor: while it is shown (+0x60 bit 7) its +0x3a8 effect stops (0203c650) and
 * clears; then the base teardown runs. */

#include "nitro/types.h"

typedef struct { u16 lo : 8; u16 hi : 8; } flags16;

extern void TaskList_FinishByTag(int model, int handle);
extern void Ov107_AiState_PostTickBase(char *self);

void Ov238_Teardown(char *self)
{
    if ((((flags16 *)(self + 0x60))->lo & 0x80) && *(int *)(self + 0x3a8) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(self + 0x3a8));
        *(int *)(self + 0x3a8) = 0;
    }
    Ov107_AiState_PostTickBase(self);
}
