/* Returns the address of entry `i` of record `a` (the halfword array at +0xba, stride 4)
 * when the index is inside Slot_CalcRangeCap18(a)'s count and the corresponding count halfword
 * -- reached through the separate symbol data_0204c732, which is gPartyMembers + 0xba --
 * is non-zero.  NULL otherwise. */
extern int Slot_CalcRangeCap18(int a);
extern unsigned char data_0204c732[];
extern unsigned char gPartyMembers[];

unsigned short *Slot_GetEntryIfCounted(int a, int i) {
    unsigned short *r = 0;
    int n = Slot_CalcRangeCap18(a);
    if (i >= 0 && i < n &&
        *(unsigned short *)(data_0204c732 + a * 260 + i * 4) != 0) {
        r = (unsigned short *)(gPartyMembers + a * 260 + 0xba + i * 4);
    }
    return r;
}
