/* Swoop enter tick of an ov257 state: the owner's +0x24 hook receives note 1 of
 * data_ov257_020d325c, animation 0x1f plays, the +0x3d0 part plays motion 0x1c, +0x44, +0x74,
 * +0x75, the +0x54 timer and +0x76 clear and the tick hands over to Ov257_DoubleStrikeTick. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef struct { u16 lo; u16 hi; } Cmd4;

/* the note table seen as a word-aligned record: its note 1 follows a 4-byte word */
extern const struct { int w0; Cmd4 n1; } data_ov257_020d325c;
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_DoubleStrikeTick(int *node);

void Ov257_SwoopEnterTick(int *node)
{
    int *state = (int *)node[1];
    Cmd4 note = data_ov257_020d325c.n1;

    if (*(void (**)(int, Cmd4 *, int))(*state + 0x24) != 0) {
        (*(void (**)(int, Cmd4 *, int))(*state + 0x24))(*state, &note, 4);
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0x1f, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 0x1c, 0);
    state[0x11] = 0;
    *((unsigned char *)state + 0x74) = 0;
    *((unsigned char *)state + 0x75) = 0;
    state[0x15] = 0;
    *((unsigned char *)state + 0x76) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov257_DoubleStrikeTick);
}
