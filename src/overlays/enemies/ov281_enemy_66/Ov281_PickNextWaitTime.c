/* State step: posts tag 1, picks a new random wait between the actor's limits when the last one has
 * run out, and installs the aim-and-pick step. */

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int RandNextScaled(int range);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov281_AimPickAttack(void);

void Ov281_PickNextWaitTime(int self) {
    int *s = *(int **)(self + 4);
    Ov107_PostTagUpdate(s[0], 1, 1);
    if (s[7] <= 0) {
        int lo = *(int *)(s[0] + 0x224);
        int d = *(int *)(s[0] + 0x228) - lo;
        if (d < 0) d = -d;
        s[7] = lo + RandNextScaled(d + 1);
    }
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)&Ov281_AimPickAttack);
}
