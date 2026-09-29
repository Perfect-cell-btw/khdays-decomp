/* Lazily allocates the 0x40-byte record held at data_0204c1ec+4 out of the heap in
 * data_0204c024, then records `n` in the halfword at data_0204c1ec+0. */

#include "game/engine.h"

extern int data_0204c1ec[];
extern void *data_0204c024;

void Record_EnsureAllocatedAndSetId(int n) {
    if (data_0204c1ec[1] == 0) {
        data_0204c1ec[1] = (int)AllocFromExpHeapWrapper(0x40, data_0204c024);
    }
    *(short *)data_0204c1ec = (short)n;
}
