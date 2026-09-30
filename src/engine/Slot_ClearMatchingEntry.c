/* Clears the first entry of record `a` whose {id, value} pair equals *key.  The id half is
 * compared unsigned (ldrh) and the value half signed (ldrsh). */

#include "game/engine.h"

extern unsigned char gPartyMembers[];

void Slot_ClearMatchingEntry(int a, short *key) {
    int n = Slot_CalcRangeCap18(a);
    int i = 0;
    short *e;
    if (n > 0) {
        e = (short *)(gPartyMembers + a * 260 + 0xba);
        do {
            if (*(unsigned short *)e == *(unsigned short *)key && e[1] == key[1]) {
                *e = 0;
                return;
            }
            i = i + 1;
            e = e + 2;
        } while (i < n);
    }
}
