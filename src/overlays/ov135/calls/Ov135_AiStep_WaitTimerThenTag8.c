extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov135_AiStep_QueueAction2OnAnimEnd_3(void);

void Ov135_AiStep_WaitTimerThenTag8(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x30) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x30) = val;
    if (val < 0x3000) return;
    Ov107_PostTagUpdate(*(int *)p, 8, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov135_AiStep_QueueAction2OnAnimEnd_3);
}
