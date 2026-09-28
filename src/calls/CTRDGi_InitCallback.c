extern void OS_Terminate(void);
extern unsigned short data_02046d4c;

void CTRDGi_InitCallback(int unused, int status) {
    if ((status & 0x3f) == 1) {
        data_02046d4c = 1;
        return;
    }
    OS_Terminate();
}
