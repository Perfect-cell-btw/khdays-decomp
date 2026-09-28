extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int state);
extern int CommandPort_IsEnabled(void);

/* True when the sub-processor is ready to accept another command. */
int IsCommandAvailable(void) {
    volatile unsigned int *reg = (volatile unsigned int *)0x04fff200;
    int enabled;
    unsigned int busy;
    if (CommandPort_IsEnabled() == 0) {
        return 1;
    }
    enabled = OS_DisableInterrupts();
    *reg = 0x10;
    busy = *reg;
    OS_RestoreInterrupts(enabled);
    return busy != 0;
}
