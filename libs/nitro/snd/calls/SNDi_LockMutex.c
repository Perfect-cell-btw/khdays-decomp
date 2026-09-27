/* NitroSDK snd (snd_main.c): SNDi_LockMutex -- OS_LockMutex(&sSndMutex). */
extern void OS_LockMutex(void *p);
extern int data_02044730;

void SNDi_LockMutex(void) {
    OS_LockMutex(&data_02044730);
}
