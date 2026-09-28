/* Reset via 020cdfe8, seed +0xc with a 3-word template, then unless busy accumulate the fall
 * speed into +0x64 and on overflow latch sub-state 0xd and dispatch. */
extern int Ov252_CheckTarget(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int data_02041dc8;
struct w3 { int a, b, c; };
void Ov252_AiHoldThenQueue13(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov252_CheckTarget(param_1, 0, 1);
    *(struct w3 *)(owner + 0xc) = *(struct w3 *)&data_02041dc8;
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    int sum = *(int *)(owner + 0x64) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(owner + 0x64) = sum;
    if (sum < 0x1000) return;
    *(unsigned char *)(*(int *)owner + 0x1c7) = 0xd;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
