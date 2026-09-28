extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov205_AiStep_QueueAction2OnFlag28Clear_3(void);

void Ov205_AiWaitThenAnim11(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x2c) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x2c) = val;
    if (val < 0x4000) return;
    Ov107_PostTagUpdate(*(int *)p, 11, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov205_AiStep_QueueAction2OnFlag28Clear_3);
}
