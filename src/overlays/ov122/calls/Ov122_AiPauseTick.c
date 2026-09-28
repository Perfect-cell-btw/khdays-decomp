extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov122_stIdlePose10Advance(void);

void Ov122_AiPauseTick(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x40) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x40) = val;
    if (val <= 0x3000) return;
    *(char *)(*(int *)(p + 0x4) + 0xa8) = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov122_stIdlePose10Advance);
}
