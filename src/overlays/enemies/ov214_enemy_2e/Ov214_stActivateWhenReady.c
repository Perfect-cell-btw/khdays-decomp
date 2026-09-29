/* ov node state callback: returns until the bound subitem's ready byte [+0xad]==0, then requests a
 * pose via ov107 and advances the node state slot. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov214_StepBounceOffContact(void);
void Ov214_stActivateWhenReady(int node) {
    int *s = *(int **)(node + 4);
    if (*(unsigned char *)(s[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*s), 7, 1);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov214_StepBounceOffContact);
}
