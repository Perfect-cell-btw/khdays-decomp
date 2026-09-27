/* NitroSDK os (os_tick.c): OS_IsTickAvailable -- returns OSi_UseTick (follows OS_InitTick). */
extern unsigned short data_02044664;

int OS_IsTickAvailable(void) {
    return data_02044664;
}
