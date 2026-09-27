/* Aborts the system when the card thread is not available. */
extern int func_0200e068(void);
extern void OS_Terminate(void);

void CARD_CheckEnabled(void) {
    if (func_0200e068() == 0) {
        OS_Terminate();
    }
}
