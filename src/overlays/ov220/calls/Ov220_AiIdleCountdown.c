extern void SetIndexedSlot(void *obj, int idx, void *value);

void Ov220_AiIdleCountdown(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x14) - *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x14) = val;
    if (val > 0) return;
    *(char *)(*(int *)p + 0x1c7) = 4;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), 0);
}
