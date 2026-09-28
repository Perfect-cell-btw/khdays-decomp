/* NitroSDK spi (pm.c): PM_ForceToPowerOff -- PM_ForceToPowerOffAsync with PMi_DummyCallback, then PMi_WaitBusy. */
extern int PM_ForceToPowerOffAsync(void *fn, int *out);
extern void PMi_WaitBusy(void);
extern void PMi_DummyCallback(void);

int PM_ForceToPowerOff(void) {
    int local;
    int r = PM_ForceToPowerOffAsync((void *)PMi_DummyCallback, &local);
    if (r != 0) return r;
    PMi_WaitBusy();
    return local;
}
