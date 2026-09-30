/* Clears record `slot` of the four 0x104-byte records at gPartyMembers: the 24 entry ids (+0x3c),
 * the 15 byte pairs (+0x9c) and the 5 counters (+0x28). Codegen: every loop indexes the global
 * record directly; a `rec` pointer local puts the record address in r1 instead of the ROM's r2. */
#pragma thumb on

#include "nitro/types.h"

struct SlotEntry {
    u16 nId;
    u16 nValue;
};

struct SlotPair {
    u8 a;
    u8 b;
};

struct SlotRecord {
    u8 pad00[0x28];
    int anCount[5];                 /* 0x28 */
    struct SlotEntry aEntry[24];    /* 0x3c */
    struct SlotPair aPair[15];      /* 0x9c */
    u8 padBA[0x104 - 0xba];
};

extern struct SlotRecord gPartyMembers[];

void PartyMember_ClearLists(int slot)
{
    int i = 0;

    for (; i < 24; i++) {
        gPartyMembers[slot].aEntry[i].nId = 0;
    }
    for (i = 0; i < 15; i++) {
        gPartyMembers[slot].aPair[i].a = 0;
        gPartyMembers[slot].aPair[i].b = 0;
    }
    for (i = 0; i < 5; i++) {
        gPartyMembers[slot].anCount[i] = 0;
    }
}
