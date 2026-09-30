/* Clears the 18 halfword pairs of a party member (+0xba of its 0x104-byte record at
 * gPartyMembers). */

extern int gPartyMembers;

void PartyMember_ClearEntryPairs(int member) {
    int i = 0;
    int p = (int)&gPartyMembers + member * 0x104;
    do {
        *(unsigned short *)(p + 0xba) = 0;
        i++;
        p += 4;
    } while (i < 0x12);
}
