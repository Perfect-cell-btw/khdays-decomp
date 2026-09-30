
#include "nitro/types.h"

extern void SetIndexedSlot(int *a, int i, int v);
extern void Ov291_stSetDispFlags86(int node);
extern void Ov291_SubStateDispatch(void);
extern void Ov291_TurnTick(void);

/* Enter the state: reset the actor's sub-state bytes, clear the task's
 * work fields, cache two actor-relative pointers, then register the three
 * phase handlers (slot 1, 0, 2). */
void Ov291_AiStateInit(int *node)
{
    int *task = (int *)node[1];

    *(u8 *)(*task + 0x1c6) = 0;
    *(s8 *)(*task + 0x1c7) = -1;
    task[2] = task[1] = 0;
    task[3] = *task + 0xb0;
    task[8] = *(int *)(*task + 0x384) + 0xad;
    task[0xd] = 0;

    SetIndexedSlot(node, 1, (int)&Ov291_stSetDispFlags86);
    SetIndexedSlot(node, 0, (int)&Ov291_SubStateDispatch);
    SetIndexedSlot(node, 2, (int)&Ov291_TurnTick);
}
