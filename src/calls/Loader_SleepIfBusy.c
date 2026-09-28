/* Sleeps the loader thread while requests are pending or active; returns 1. */

extern void OS_SleepThread(void *p);
extern struct { char _0[4]; char *field_4; char _8[0x34]; int field_3c; } data_0204bbfc;

int Loader_SleepIfBusy(void)
{
    if (data_0204bbfc.field_3c <= 0) {
        if (*(int *)(data_0204bbfc.field_4 + 0x448) == 0) goto out;
    }
    OS_SleepThread(data_0204bbfc.field_4 + 0x4c + 0x400);
out:
    return 1;
}
