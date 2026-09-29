/* Set bit 0x40 in the high byte of the u16 flags at *(child)+0x60, clear +0x40, run the local
 * 020cf... pass on the child, play the anim (ov107 mode 0xa,0), fire ov107_020c5af8(*child,
 * 0x15e, 0xc, *(child+8)), then register the handler. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
extern void Ov266_SetMode70(int child, int a, int b);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov266_AlertApproachTick(int);
void Ov266_EnterAlert(int param_1) {
    int child = *(int *)(param_1 + 4);
    ((struct hw60 *)(*(int *)child + 0x60))->hi |= (unsigned char)0x40;
    *(int *)(child + 0x40) = 0;
    Ov266_SetMode70(child, 1, 0);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xa, 0);
    Ov107_BuildAndSendUpdate(*(int *)child, 0x15e, 0xc, *(int *)(child + 8));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov266_AlertApproachTick);
}
