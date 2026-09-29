/* Starts the menu sequence: resets its state, enables its two objects, sets the target slot and
 * plays the open sound. */

#include "game/engine.h"

extern void Ov008_SetCtxField9678(int arg0);
extern void Ov008_SetCtxObject9630(int arg0);
extern void Ov008_SetCtxObject9634(int arg0);
extern void Ov008_SetTargetSlot(int arg0, int arg1);

void Ov008_InitSequence(void)
{
    int value = 1;

    Ov008_SetCtxField9678(0);
    Ov008_SetCtxObject9630(value);
    Ov008_SetCtxObject9634(value);
    Ov008_SetTargetSlot(value, value - 2);
    PlaySound(0, value);
}
