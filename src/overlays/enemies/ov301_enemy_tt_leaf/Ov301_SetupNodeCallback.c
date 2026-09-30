/* AI step: sets the contact flags, clamps the actor's value and continues with the idle step. */

extern int SetIndexedSlot(void *obj, int slot, void *cb);
extern void Ov301_NodeCallbackIdleStep(void);

int Ov301_SetupNodeCallback(void *obj) {
    int *p = *(int **)((char *)obj + 4);
    char *a = (char *)*p + 0x100;
    *(unsigned short *)(a + 0xae) |= 3;
    {
        short s = *(short *)((char *)*p + 0x218);
        *(unsigned short *)((char *)*p + 0x21a) = (s >= 0) ? 0 : s;
    }
    return SetIndexedSlot(obj, *(signed char *)((char *)obj + 0x20), (void *)Ov301_NodeCallbackIdleStep);
}
