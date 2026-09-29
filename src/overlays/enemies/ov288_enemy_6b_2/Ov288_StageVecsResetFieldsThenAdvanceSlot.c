/* State step: posts pose 1, sets the alpha to its minimum, remembers the start position, clears the
 * velocity and counters and installs the throw step. */

#include "game/enemy_common.h"

extern int data_02041dc8;
extern void SetIndexedSlot();
extern void Ov288_Throw_Tick(void);

struct w3 { int a, b, c; };

void Ov288_StageVecsResetFieldsThenAdvanceSlot(int this_) {
    int holder = *(int *)(this_ + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)holder), 1, 0);
    *(int *)(*(int *)holder + 0x394) = 1;
    *(struct w3 *)(holder + 0x10) = *(struct w3 *)(*(int *)(holder + 0xc));
    *(struct w3 *)(holder + 0x1c) = *(struct w3 *)&data_02041dc8;
    *(int *)(holder + 8) = 0;
    *(int *)(holder + 0x58) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov288_Throw_Tick);
}
