extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov240_AiIdleCountdown(void);

void Ov240_AiEnterIdle(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x38) = 0x1000;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov240_AiIdleCountdown);
}
