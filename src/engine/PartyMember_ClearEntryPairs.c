/* Clears the 18 halfword pairs of a party member (+0xba of its 0x104-byte record at
 * data_0204c678). */

extern int data_0204c678;

void PartyMember_ClearEntryPairs(int member) {
    int i = 0;
    int p = (int)&data_0204c678 + member * 0x104;
    do {
        *(unsigned short *)(p + 0xba) = 0;
        i++;
        p += 4;
    } while (i < 0x12);
}
