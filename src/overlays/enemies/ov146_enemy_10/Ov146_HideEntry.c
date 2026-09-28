/* Hide entry of the ov146 actor: its partner (+8) is released from mode 0 (020ce298), bits 1, 2 and 7 of
 * the +0x60 high byte are set, the +0x3ac shape hides and the node moves on to 020ccdf4. */
#include "nitro/types.h"
typedef struct { unsigned f : 8; } B8;

extern int Ov146_Rider_SetFlagIfReady(int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov146_BeginQueuedPose(void);

void Ov146_HideEntry(int *node)
{
    int *state = (int *)node[1];

    Ov146_Rider_SetFlagIfReady(state[2], 0);
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x86) << 0x18) >> 0x10);
    }
    ((B8 *)(*(int *)(*state + 0x3ac) + 8))->f &= ~1;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov146_BeginQueuedPose);
}
