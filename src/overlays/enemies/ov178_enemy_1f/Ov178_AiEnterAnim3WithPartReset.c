/* Resets the part, plays anim 3 and installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov178_ForwardToAiTaskWhenReady();
extern void Ov178_HoverTick(void);
void Ov178_AiEnterAnim3WithPartReset(int node) {
    int *s = *(int **)(node + 4);
    Ov178_ForwardToAiTaskWhenReady(*(int *)(*s + 0x3ac));
    Ov107_PostTagUpdate((Actor *)(*s), 3, 0);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov178_HoverTick);
}
