/* NitroSDK OS: reset notification (command 0x10) sets the reset flag; anything else panics. */

extern void OS_Terminate(void);
extern unsigned short data_02044694;

void OSi_CommonCallback(int unused, int status) {
    if ((unsigned int)((status & 0x7f00) << 8) >> 16 == 0x10) {
        data_02044694 = 1;
        return;
    }
    OS_Terminate();
}
