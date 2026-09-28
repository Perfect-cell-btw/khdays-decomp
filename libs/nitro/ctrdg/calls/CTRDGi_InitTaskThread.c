/* NitroSDK CTRDG: once, creates and starts the cartridge task thread on the given work. */

extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned stackSize, unsigned prio);
extern void OS_WakeupThreadDirect(void *thread);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int state);
extern void MIi_CpuFill24(void *p);
extern void JobQueue_WorkerLoop(void *arg);

extern void *data_02046f28;
extern char data_02046f2c;
extern char data_02047350;

void CTRDGi_InitTaskThread(char *p) {
    int state = OS_DisableInterrupts();
    if (data_02046f28 == 0) {
        data_02046f28 = p;
        MIi_CpuFill24(p + 0xc4);
        MIi_CpuFill24(&data_02046f2c);
        *(int *)(p + 0xc0) = 0;
        OS_CreateThread(p, JobQueue_WorkerLoop, p, &data_02047350, 0x400, 0x14);
        OS_WakeupThreadDirect(p);
    }
    OS_RestoreInterrupts(state);
}
