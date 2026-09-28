/* After 0x800 sets the wind-up speed and installs the wind-up tick. */

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov114_WindupTick(void);

void Ov114_AiSwingRecover(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x44) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x44) = val;
    if (val <= 0x800) return;
    *(int *)(p + 0x68) = 0x300;
    p[0x49] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov114_WindupTick);
}
