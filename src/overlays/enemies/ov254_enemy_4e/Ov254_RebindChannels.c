/* Re-bind the +0x384 rig's channels 0, 2 and 4 to the +0x310 mode with the +0x311 bit-0 flag and
 * re-init it. */
#include "nitro/types.h"
struct Flag311 { u8 b0 : 1; };

extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);

void Ov254_RebindChannels(char *self)
{
    SetSubitemState(*(int *)(self + 0x384), 0, *(signed char *)(self + 0x300 + 0x10), ((struct Flag311 *)(self + 0x311))->b0);
    SetSubitemState(*(int *)(self + 0x384), 2, *(signed char *)(self + 0x300 + 0x10), ((struct Flag311 *)(self + 0x311))->b0);
    SetSubitemState(*(int *)(self + 0x384), 4, *(signed char *)(self + 0x300 + 0x10), ((struct Flag311 *)(self + 0x311))->b0);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}
