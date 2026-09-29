/* Ov236_ReactionStepNotify -- reaction step: while the gate byte at *node[9] is clear, notify the owner
 * with the constant pair at data_ov236_020d63e8+8 (event 4), fire attack 0xe and hand off to
 * Ov236_ClawSwipeTick.
 * The pair is copied member-wise HIGH HALFWORD FIRST and through a local pointer, which is what
 * puts `&pair` in a register before the copy and the two `ldrh` in the ROM's order. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov236_ClawSwipeTick(void);
extern char data_ov236_020d63e8[];

struct Pair16 { unsigned short a, b; };

void Ov236_ReactionStepNotify(int self) {
    int *node = *(int **)(self + 4);
    struct Pair16 pair;
    struct Pair16 *ps;
    void (*cb)(int, void *, int);
    if (*(unsigned char *)node[9] != 0) {
        return;
    }
    ps = &pair;
    ps->b = ((struct Pair16 *)(data_ov236_020d63e8 + 8))->b;
    ps->a = ((struct Pair16 *)(data_ov236_020d63e8 + 8))->a;
    cb = *(void (**)(int, void *, int))(node[0] + 0x24);
    if (cb != 0) {
        cb(node[0], ps, 4);
    }
    Ov107_PostTagUpdate((Actor *)node[0], 0xe, 1);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (int)&Ov236_ClawSwipeTick);
}
