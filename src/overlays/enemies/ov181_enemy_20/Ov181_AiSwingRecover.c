/* After 0x800 sets the wind-up speed and installs the wind-up step. */

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov181_StepWindUp(void);

void Ov181_AiSwingRecover(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x1c) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x1c) = val;
    if (val <= 0x800) return;
    *(int *)(p + 0x70) = 0x300;
    p[0x50] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov181_StepWindUp);
}
