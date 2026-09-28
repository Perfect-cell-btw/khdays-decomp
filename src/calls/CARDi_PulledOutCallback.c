/* NitroSDK CARD: on the pulled-out notification (0x11) runs the user hook once and terminates
 * unless it declines; any other command panics. */

extern void OS_Terminate(void);
extern void CARD_TerminateForPulledOut(void);
extern int data_02046d40;

void CARDi_PulledOutCallback(int arg0, int arg1) {
    if ((arg1 & 0x3f) == 0x11) {
        if (data_02046d40 != 0) return;
        data_02046d40 = 1;
        {
            int (*fn)(void) = *(int (**)(void))((char *)&data_02046d40 + 4);
            int r = 1;
            if (fn != 0) r = fn();
            if (r != 0) CARD_TerminateForPulledOut();
        }
    } else {
        OS_Terminate();
    }
}
