extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov147_TickHoldTimer(void);

void Ov147_AiEnterHold(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 0);
    *(int *)(p + 0x40) = 0x2000;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov147_TickHoldTimer);
}
