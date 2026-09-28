extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov251_LungeTick(void);

void Ov251_AiSwingRecover(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x1c) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x1c) = val;
    if (val <= 0x800) return;
    *(int *)(p + 0x70) = 0x300;
    p[0x50] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov251_LungeTick);
}
