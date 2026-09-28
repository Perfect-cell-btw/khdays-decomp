/* Ov006_ForwardRtcAvailability -- sample the RTC-availability flag and forward it, ov006. */
extern int func_01ff8138(void);
extern void Ov006_CountPlayersInMask(short *p);
void Ov006_ForwardRtcAvailability(void) {
    short avail = func_01ff8138();
    Ov006_CountPlayersInMask(&avail);
}
