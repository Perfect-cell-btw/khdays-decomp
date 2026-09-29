/* Poll 020cd524: on failure dispatch. If +8 is live, seed the finish state (+0x5c=1, +0x54=0,
 * +0x60=0xb, sub-state 4) and dispatch; otherwise tick +0x61 with anim 0x11 until 3 then go 020cf33c. */
extern int Ov248_MeasureTargetGap(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov248_Burst(int);
void Ov248_AiBurstWindup(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov248_MeasureTargetGap(param_1) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
        return;
    }
    if (*(int *)(owner + 8) != 0) {
        *(int *)(owner + 0x5c) = 1;
        *(int *)(owner + 0x54) = 0;
        *(unsigned char *)(owner + 0x60) = 0xb;
        *(unsigned char *)(*(int *)owner + 0x1c7) = 4;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
        return;
    }
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) == 0) {
        Ov107_PostTagUpdate(*(int *)owner, 0x11, 0);
        *(unsigned char *)(owner + 0x61) += 1;
    }
    if (*(unsigned char *)(owner + 0x61) < 3) return;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov248_Burst);
}
