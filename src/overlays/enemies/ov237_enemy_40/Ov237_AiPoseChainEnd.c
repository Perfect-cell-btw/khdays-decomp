/* Fetch the target vector via 020cdb50 into +0x3c; unless busy mark state 2 and dispatch. */
extern void Ov237_RotateByActorHeading(void *out, int self, int arg);
extern int SetIndexedSlot(int, int, int);
struct w3 { int a, b, c; };
void Ov237_AiPoseChainEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    struct w3 buf;
    Ov237_RotateByActorHeading(&buf, param_1, *(int *)(*(int *)owner + 0x3d8) + 0x2c);
    *(struct w3 *)(owner + 0x3c) = buf;
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
