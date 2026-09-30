/* Plays looping anim 1, arms the 0x1000 timer and installs the countdown. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov239_AiIdleCountdown(void);

void Ov239_AiEnterIdle(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x2c) = 0x1000;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov239_AiIdleCountdown);
}
