/* Returns a byte of the object a global points to. */

extern int data_ov006_020565e4;
int Ov006_IsMissionMenuExitRequested(void) {
    return *(unsigned char *)(*(int *)&data_ov006_020565e4 + 0x4ef);
}
