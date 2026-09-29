/*
 * Ov002_RefreshWindowCallback - arm a one-shot subsystem flag once its preconditions hold (ARM).
 *
 * Reads the subsystem state at *(int*)&data_ov002_0207f600. Does nothing if it is already active
 * (state bit 2 set, or the latch already non-zero), or if the required-ready bits (bit 0 and bit 4)
 * are not both set. When those pass it sets the latch to 1, first running the deferred-init call
 * SetMasterBrightnessMain(0) unless bit 3 indicates init already happened. The subsystem pointer is re-read
 * after the call because it may have moved.
 */

#include "game/engine.h"

typedef struct {
    int flags;            /* +0x00 */
    char _4[0x40 - 4];
    int latch;            /* +0x40 */
} Ov002Sub;

extern int data_ov002_0207f600;

void Ov002_RefreshWindowCallback(void)
{
    Ov002Sub *s = *(Ov002Sub **)&data_ov002_0207f600;
    int flags = s->flags;
    if ((flags & 4) || s->latch != 0) return;
    if ((flags & 1) == 0) return;
    if ((flags & 0x10) == 0) return;
    if ((flags & 8) == 0) SetMasterBrightnessMain(0);
    (*(Ov002Sub **)&data_ov002_0207f600)->latch = 1;
}
