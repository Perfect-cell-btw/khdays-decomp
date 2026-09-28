/* Once 020cce48 clears, retarget the linked node, restart sub-anim 020c9ee8, drive +0x28 to
 * -0x4000, copy the parent's +8 into +0x30 and dispatch 020ce1cc. */
extern int Ov245_AnimGate(int);
extern int Ov245_NodeUpdateTickForward_c(int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_HoverArmedTick(int);
void Ov245_AiHoverArmStart(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov245_AnimGate(*(int *)owner) != 0) return;
    Ov245_NodeUpdateTickForward_c(*(int *)(*(int *)owner + 0x434), *(int *)(owner + 0x24));
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x4c8), 0, 1);
    *(int *)(owner + 0x28) = -0x4000;
    *(int *)(owner + 0x30) = *(int *)(*(int *)(owner + 8) + 8);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_HoverArmedTick);
}
