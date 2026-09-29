/* Play the anim (ov107 mode 0xd) on *child and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_ReactionStepNotify(int);
void Ov236_RidersA_AiEnterReaction(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0xd, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_ReactionStepNotify);
}
