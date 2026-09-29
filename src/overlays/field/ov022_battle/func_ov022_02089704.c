/* Per-frame network send: the host sends the actor states and pending damage, everyone sends the
 * control packet (unless paused). */

#include "game/engine.h"

extern unsigned int *NNSi_FndGetCurrentRootHeap(void);
extern void Ov022_SendActorStatePacket(void);
extern void func_ov022_02089e20(void);
extern void Ov022_SendControlPacket(void);
int func_ov022_02089704(void) {
    unsigned int *p = NNSi_FndGetCurrentRootHeap();
    if (*p & 1) return 0;
    if (Session_GetLocalPlayerIndex() == 0) {
        Ov022_SendActorStatePacket();
        func_ov022_02089e20();
    }
    Ov022_SendControlPacket();
    return 0;
}
