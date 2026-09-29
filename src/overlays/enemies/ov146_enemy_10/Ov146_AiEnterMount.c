/* Set bit0 of both bodies' +0x1ae, OR 2 into the shared +0x3ac->+8 byte, anim 8 on body/anim 7 on
 * child + step it, arm the 0x125/6 timer with +0xc, flag +0x58 and dispatch 020cd7bc. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov146_ForwardToAiTaskWhenReady(int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov146_AiQueue7OnAnimEnd_2(int);
struct b8 { unsigned f : 8; };
void Ov146_AiEnterMount(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(unsigned short *)(*(int *)owner + 0x1ae) |= 1;
    *(unsigned short *)(*(int *)(owner + 8) + 0x1ae) |= 1;
    ((struct b8 *)(*(int *)(*(int *)(owner + 8) + 0x3ac) + 8))->f |= 2;
    Ov107_PostTagUpdate(*(int *)owner, 8, 0);
    Ov107_PostTagUpdate(*(int *)(owner + 8), 7, 0);
    Ov146_ForwardToAiTaskWhenReady(*(int *)(owner + 8));
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x125, 6, *(int *)(owner + 0xc));
    *(int *)(owner + 0x58) = 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_AiQueue7OnAnimEnd_2);
}
