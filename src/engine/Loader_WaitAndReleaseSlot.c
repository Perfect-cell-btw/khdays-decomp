/* When the index is valid waits for the loader, then releases the VM's resource slot. */

extern void Loader_SleepIfBusy(int a, int b, int c, int d);
extern void ResSlot_Release(void *a);

void Loader_WaitAndReleaseSlot(int param_1, int param_2, int param_3, int param_4) {
    if (param_2 >= 0) {
        Loader_SleepIfBusy(param_1, param_2, param_3, param_4);
        ResSlot_Release(*(void **)(*(int *)(param_1 + 0x128) + 0x28));
    }
}
