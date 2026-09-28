/* Draw pre-pass of the ov259 actor: effects that outlive their move end (+0x46c outside move 0x11;
 * +0x45c unless move 0x11 keeps it while the +0x384 rig is airborne and 020d1838 holds; +0x474 in
 * move 0xf), then the base pre-pass runs. */
#include "nitro/types.h"
struct Flag17a { u8 b0 : 1; };

extern void TaskList_FinishByTag(void *taskList, void *handle);
extern int Ov259_Helper_IsHeld(int rig);
extern void Ov107_AiState_PostTickBase(char *self);

void Ov259_DrawPrePass(char *self)
{
    if (*(signed char *)(self + 0x100 + 0xc6) != 0x11 && *(void **)(self + 0x46c) != 0) {
        TaskList_FinishByTag(*(void **)(self + 0x3c), *(void **)(self + 0x46c));
        *(void **)(self + 0x46c) = 0;
    }
    if (*(signed char *)(self + 0x100 + 0xc6) != 0x11 ||
        ((struct Flag17a *)(*(int *)(self + 0x384) + 0x17a))->b0 ||
        Ov259_Helper_IsHeld(*(int *)(self + 0x384)) == 0) {
        if (*(void **)(self + 0x45c) != 0) {
            TaskList_FinishByTag(*(void **)(self + 0x3c), *(void **)(self + 0x45c));
            *(void **)(self + 0x45c) = 0;
        }
    }
    if (*(signed char *)(self + 0x100 + 0xc6) == 0xf && *(void **)(self + 0x474) != 0) {
        TaskList_FinishByTag(*(void **)(self + 0x3c), *(void **)(self + 0x474));
        *(void **)(self + 0x474) = 0;
    }
    Ov107_AiState_PostTickBase(self);
}
