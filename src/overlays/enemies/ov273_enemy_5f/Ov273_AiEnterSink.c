/* Play the anim (ov107 mode 0xe), clear bit 0x40 in the high byte of the u16 flags at
 * *(child)+0x60 and register the handler. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_AiSinkStart(int);
void Ov273_AiEnterSink(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xe, 0);
    ((struct hw60 *)(*(int *)child + 0x60))->hi &= ~0x40;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_AiSinkStart);
}
