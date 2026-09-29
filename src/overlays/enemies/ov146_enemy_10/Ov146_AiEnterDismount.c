/* Set bit0 of both bodies' +0x1ae, OR 2 into the shared +0x3ac->+8 byte, kick anim 9 on the body
 * and anim 8 on the child, step the child, then dispatch 020cd88c. */

#include "game/enemy_common.h"

extern int Ov146_ForwardToAiTaskWhenReady(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov146_AiDismountRiderWait(int);
struct b8 { unsigned f : 8; };
void Ov146_AiEnterDismount(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(unsigned short *)(*(int *)owner + 0x1ae) |= 1;
    *(unsigned short *)(*(int *)(owner + 8) + 0x1ae) |= 1;
    ((struct b8 *)(*(int *)(*(int *)(owner + 8) + 0x3ac) + 8))->f |= 2;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 9, 0);
    Ov107_PostTagUpdate((Actor *)(*(int *)(owner + 8)), 8, 0);
    Ov146_ForwardToAiTaskWhenReady(*(int *)(owner + 8));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_AiDismountRiderWait);
}
