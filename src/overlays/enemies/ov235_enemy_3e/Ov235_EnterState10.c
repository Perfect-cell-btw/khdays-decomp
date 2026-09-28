/* Enter tick of an ov235 state: the owner's +0x24 hook receives note 2 of the
 * data_ov235_020d24d0 table (4 bytes), animation 0x10 plays, the +0x54 timer and the +0x65 flag
 * clear and the tick hands over to func_ov235_020cf664. */
#include "nitro/types.h"
typedef struct { u16 lo; u16 hi; } Cmd4;

extern const struct { Cmd4 n[4]; } data_ov235_020d24d0;
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void func_ov235_020cf664(int *node);

void Ov235_EnterState10(int *node)
{
    int *state = (int *)node[1];
    Cmd4 note = data_ov235_020d24d0.n[2];

    if (*(void (**)(int, Cmd4 *, int))(*state + 0x24) != 0) {
        (*(void (**)(int, Cmd4 *, int))(*state + 0x24))(*state, &note, 4);
    }
    Ov107_PostTagUpdate(*state, 0x10, 0);
    state[0x15] = 0;
    *((u8 *)state + 0x65) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)func_ov235_020cf664);
}
