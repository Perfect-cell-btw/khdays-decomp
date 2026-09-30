/* Decay the value at *(obj)+0x57c toward 0 by 0x180/0x1000 each frame; once it drops to 0x200
 * or below, run ov266_020d0200, play the anim (ov107 mode 8) and register the handler. */
extern void Ov266_FlagSlotsDirty(int a);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov266_AiStep_QueueAction2OnAnimEnd(int);
void Ov266_AiShrinkTick(int param_1) {
    int child = *(int *)(param_1 + 4);
    int obj = *(int *)child;
    int base = *(int *)(obj + 0x57c);
    *(int *)(obj + 0x57c) = base + (-base * 0x180) / 0x1000;
    if (*(int *)(*(int *)child + 0x57c) > 0x200) return;
    Ov266_FlagSlotsDirty(child);
    Ov107_PostTagUpdate(*(int *)child, 8, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov266_AiStep_QueueAction2OnAnimEnd);
}
