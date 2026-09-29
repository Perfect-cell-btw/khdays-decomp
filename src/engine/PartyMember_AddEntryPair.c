/* Stores a pair in the first free one of a party member's halfword pairs (+0xba of its 0x104-byte
 * record at data_0204c678), up to Slot_CalcRangeCap18(member) pairs. */

#include "game/engine.h"

extern int data_0204c678;

void PartyMember_AddEntryPair(int member, unsigned short *pair) {
    unsigned int n = Slot_CalcRangeCap18(member);
    int i = 0;
    if ((int)n > 0) {
        unsigned short *p = (unsigned short *)((int)&data_0204c678 + member * 0x104 + 0xba);
        do {
            if (*p == 0) {
                *p = *pair;
                p[1] = pair[1];
                return;
            }
            i++;
            p += 2;
        } while (i < (int)n);
    }
}
