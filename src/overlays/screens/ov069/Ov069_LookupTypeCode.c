/* Advance Session_GetLocalPlayerIndex, then map the current Slot4_GetIfOccupied slot to a priority
 * table, storing its index. */

#include "game/engine.h"

extern void *Slot4_GetIfOccupied();
extern int data_ov069_020ba9b8;

int Ov069_LookupTypeCode(int this_) {
    int result = 0xa;
    void *r;
    r = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex());
    if (r != 0) {
        result = (&data_ov069_020ba9b8)[*(int *)((char *)r + 4)];
    }
    if (this_ != 0) {
        *(int *)this_ = *(int *)((char *)r + 4);
    }
    return result;
}
