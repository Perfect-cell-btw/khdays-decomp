/* Ov000_List_PageUp -- fast-scroll the logo list by up to 0xa rows, ov000. No-op if
 * already at the top (field[0]==0) or while the L/R shoulder keys are held
 * (gPadHeld & 0xc0). Moves field[0]/field[1] up by 0xa (or to the top). */

#include "game/engine.h"

extern unsigned short gPadHeld;
extern void Ov000_QueueResourceTransfers(void);
void Ov000_List_PageUp(short *s) {
    if (s[0] == 0) return;
    if (gPadHeld & 0xc0) return;
    if (s[0] >= 0xa) {
        s[0] -= 0xa;
        s[1] -= 0xa;
    } else {
        s[1] -= s[0];
        s[0] = 0;
    }
    *(int *)((char *)s + 0x60) = 0;
    PlaySound(0, 0);
    Ov000_QueueResourceTransfers();
}
