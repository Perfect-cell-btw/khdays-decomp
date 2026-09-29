/* Selects a slot for the local player (its sprite depends on whether the object is free) and
 * restarts the selection tween when the slot changes. */

#include "game/engine.h"

extern int Ov002_IsObjectFree(int a, int b);
extern void Tween_Configure(int a, int b, int c, int d, int e);
extern void Tween_Start(int a);

void Ov022_SelectSlotAndRestartAnim(int arg0, int arg1) {
    int kind = *(unsigned char *)(GetEntryField20ByIndex(QueryActiveStateOrDelegate()) + 9);
    int sel = 0;
    if (Ov002_IsObjectFree(arg1, kind) == 0) sel = 1;
    if (*(int *)(arg0 + 0x128) == arg1) {
        *(int *)(arg0 + 0x120) = sel * 0x30 + (arg0 + 0xc0);
        return;
    }
    *(int *)(arg0 + 0x128) = arg1;
    *(int *)(arg0 + 0x124) = 1;
    *(int *)(arg0 + 0x120) = sel * 0x30 + (arg0 + 0xc0);
    Tween_Configure(arg0 + 0x12c, 2, 0x2d000, 0, 400);
    Tween_Start(arg0 + 0x12c);
}
