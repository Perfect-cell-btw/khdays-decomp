/* Read the u16 at +0x434 of the ov006 global object, or 0 if absent. */
extern int data_ov006_020565e4;
int Ov006_GetMissionOptionMask(void) {
    if (data_ov006_020565e4 != 0) return *(unsigned short *)(data_ov006_020565e4 + 0x434);
    return 0;
}
