extern void Ov107_LoadMsUpRecord(int *self, int arg);

typedef void (*func_ov237_020ccfb4_cb)(int *target, int arg);

void Ov237_NotifyPartnerThenBase(int *self, int arg) {
    int *target = (int *)self[0x4a4 / 4];
    if (target != 0 && target[0x1f0 / 4] != 0) {
        ((func_ov237_020ccfb4_cb)target[0x1f0 / 4])(target, arg);
    }
    Ov107_LoadMsUpRecord(self, arg);
}
