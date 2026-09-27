/* NitroSDK snd (snd_main.c): SNDi_UnlockMutex -- OS_UnlockMutex(&sSndMutex). */
extern void OS_UnlockMutex(void *p);
extern int data_02044730;

void SNDi_UnlockMutex(void) {
    OS_UnlockMutex(&data_02044730);
}
