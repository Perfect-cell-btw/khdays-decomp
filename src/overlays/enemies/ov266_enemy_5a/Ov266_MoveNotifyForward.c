/* Ov266_MoveNotifyForward -- move the object, notify the owner's callback, latch the ready flag, and
 * forward to the finaliser in state 1.
 *
 * One of a 3-member shape family; the twins live in ov212/ov267 and are byte-identical modulo
 * relocs (matched here, fanned out with dedupprop).
 *
 * Same callback protocol as Ov212_NotifyAndFinalise: the gate at +0x40 is a SIGNED 1-bit bitfield at
 * bit 1 (the ROM's `lsl #0x1e ; asrs #0x1f` sign-extends and tests in one), and the callback at
 * +0xc must be read INSIDE the short-circuit -- the ROM's `ldrne` only loads it when the gate is
 * set. See codegen-cracks.md. */

#include "game/enemy_common.h"

typedef struct {
    int b0 : 1;
    int b1 : 1;
    int rest : 30;
} Bits32;

extern void RefreshObjectCallbacks(int a, int b);
extern void Ov266_LockOnTarget(int a, int b, int c);

void Ov266_MoveNotifyForward(int obj, int a, int b, int c) {
    Ov107_MoveNodeAndRelayout((Actor *)obj, (VecFx32 *)a);
    if (((Bits32 *)(obj + 0x40))->b1 != 0 && *(void (**)(int, int))(obj + 0xc) != 0) {
        (*(void (**)(int, int))(obj + 0xc))(obj, 0);
    }
    RefreshObjectCallbacks(*(int *)(obj + 0x384), 0);
    *(int *)(obj + 0x388) = 1;
    if (*(int *)(obj + 0x50) == 1) {
        Ov266_LockOnTarget(*(int *)(obj + 0x214), b, c);
    }
}
