/* Ov008_HandleCancelFlags -- Ov008_HandleCancelFlags (116 B, 5 relocs).
 * Reacts to the menu's flag halfword at ctx+0x5c6. If bit 7 is set the request is suppressed and
 * it returns immediately. Otherwise, when bit 5 is set it plays the cancel feedback
 * (Ov008_Menu_ToggleDetailPanel(0)) and posts event (0, 3); when bit 5 is clear it looks up object 0x200c
 * (GameState_IsFlagSet), resolves its node (Ov008_GetSharedRecord), and if present sets bit 2 of the
 * node's byte flags before signalling Ov008_PrimeSubSceneFromCursor(8). The two flag tests read single
 * bitfield members so the compiler emits the lsl/lsr bit extracts. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008Flags5c6 {
    u16 pad0 : 5;
    u16 bit5 : 1;   /* 0x20 */
    u16 pad6 : 1;
    u16 bit7 : 1;   /* 0x80 */
    u16 pad8 : 8;
} Ov008Flags5c6;

typedef struct EdObj {
    u8 pad_0000[2];
    u8 flags2;      /* 0x2 */
} EdObj;

extern void   Ov008_Menu_ToggleDetailPanel(int a);
extern EdObj *Ov008_GetSharedRecord(void *x);
extern void   Ov008_PrimeSubSceneFromCursor(int a);

void Ov008_HandleCancelFlags(void *ctx)
{
    Ov008Flags5c6 *f = (Ov008Flags5c6 *)((char *)ctx + 0x5c6);
    void *x;
    EdObj *y;

    if (f->bit7) {
        return;
    }
    if (f->bit5) {
        Ov008_Menu_ToggleDetailPanel(0);
        PlaySound(0, 3);
        return;
    }
    x = GameState_IsFlagSet(0x200c);
    if (x == 0) {
        return;
    }
    y = Ov008_GetSharedRecord(x);
    if (y == 0) {
        return;
    }
    y->flags2 |= 4;
    Ov008_PrimeSubSceneFromCursor(8);
}
