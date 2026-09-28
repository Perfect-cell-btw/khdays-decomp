extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov219_AiIdleCountdown(void);

void Ov219_AiEnterIdle(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 0, 1);
    *(int *)(p + 0x14) = 0x1000;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov219_AiIdleCountdown);
}
