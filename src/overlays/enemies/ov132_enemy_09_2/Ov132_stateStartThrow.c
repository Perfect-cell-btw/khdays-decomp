/* State step: once the gate byte is clear, sends the throw message, posts pose 7, clears the
 * release flag and the thrown object's motion, clears flag 0x40 in the high byte of the actor's
 * flags and installs the throw step. */

#include "game/enemy_common.h"

struct v3 { int a, b, c; };
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
struct pair { unsigned short a, b; };

extern unsigned short data_ov132_020d0d8c[];
extern struct v3 data_02041dc8;
extern void func_02031384();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov132_ThrowCharge_Tick(void);

void Ov132_stateStartThrow(char *obj) {
    int *state = *(int **)(obj + 4);
    struct pair buf;
    if (*(unsigned char *)state[0x12] != 0) return;
    buf = *(struct pair *)&data_ov132_020d0d8c[2];
    buf.a = *(unsigned short *)(*state + 2);
    func_02031384(4, &buf, 4);
    Ov107_PostTagUpdate((Actor *)(*state), 7, 1);
    *(int *)(*state + 0x3cc) &= ~1;
    *(struct v3 *)((char *)state + 0x24) = data_02041dc8;
    state[0x16] = 0;
    state[0xc] = 0;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x40;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov132_ThrowCharge_Tick);
}
