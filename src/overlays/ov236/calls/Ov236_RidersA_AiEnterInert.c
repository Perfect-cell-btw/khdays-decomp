/* Clear flags 1,2 in the high byte of the u16 at (*child)+0x60, set bit0 of the
 * u16 at +0x1ae, then dispatch. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_RidersA_InertIdleStep(void);
struct hi_020cfb2c { unsigned short pad : 8; unsigned short flags : 8; };
void Ov236_RidersA_AiEnterInert(int param_1) {
    int child = *(int *)(param_1 + 4);
    ((struct hi_020cfb2c *)(*(int *)child + 0x60))->flags &= ~6;
    *(unsigned short *)(*(int *)child + 0x1ae) |= 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_RidersA_InertIdleStep);
}
