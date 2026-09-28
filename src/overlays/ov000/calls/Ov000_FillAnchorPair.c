/* Fill a 2-word buffer for Ov000_SetEntryPosition: for each slot, if the matching
 * param_2 flag bit 2 (+0x64 / +0x80) is set, copy from the Ov000_GetEntryPosition
 * result; otherwise compute it via Tween_Sample from param_2->+0x4c / +0x68. */
extern int Ov000_GetEntryPosition(int param_1);
extern void Tween_Sample(int src, void *dst);
extern void Ov000_SetEntryPosition(int param_1, int param_2, void *buf);
struct bf3 { unsigned int b0:1, b1:1, b2:1; };
void Ov000_FillAnchorPair(int param_1, int param_2) {
    int buf[2];
    int *r = (int *)Ov000_GetEntryPosition(param_1);
    if (((struct bf3 *)(param_2 + 0x64))->b2) {
        buf[0] = r[0];
    } else {
        Tween_Sample(param_2 + 0x4c, &buf[0]);
    }
    if (((struct bf3 *)(param_2 + 0x80))->b2) {
        buf[1] = r[1];
    } else {
        Tween_Sample(param_2 + 0x68, &buf[1]);
    }
    Ov000_SetEntryPosition(param_1, param_2, buf);
}
