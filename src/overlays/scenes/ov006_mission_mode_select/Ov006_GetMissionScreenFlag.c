/* Ov006_GetMissionScreenFlag -- read the current-screen flag byte, ov006. Indexes the ov006
 * context (*data_ov006_020565e4) by the RTC-available bit and reads byte @+0x48e. */
extern int func_01ff8128(void);
extern char *data_ov006_020565e4;
int Ov006_GetMissionScreenFlag(void) {
    return *(unsigned char *)(data_ov006_020565e4 + func_01ff8128() + 0x48e);
}
