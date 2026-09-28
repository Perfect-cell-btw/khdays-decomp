/* Follows the head offset; when the animation ends plays anim 3 and model anim 2. */

extern void Ov237_RotateByActorHeading(void *out, int self, int arg);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov237_AiPoseChainEnd(int);
struct w3 { int a, b, c; };
void Ov237_AiPoseChain3(int param_1) {
    int owner = *(int *)(param_1 + 4);
    struct w3 buf;
    Ov237_RotateByActorHeading(&buf, param_1, *(int *)(*(int *)owner + 0x3d8) + 0x2c);
    *(struct w3 *)(owner + 0x3c) = buf;
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 3, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x3d8), 2, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov237_AiPoseChainEnd);
}
