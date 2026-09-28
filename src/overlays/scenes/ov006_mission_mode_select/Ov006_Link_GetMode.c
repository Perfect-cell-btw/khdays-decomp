/* Mode byte of the link state (+0x100). */

/* Read the u8 field at (*(&data)) + 0x100. */
extern int data_ov006_020565e4;
int Ov006_Link_GetMode(void) {
    return *(unsigned char *)(*(int *)&data_ov006_020565e4 + 0x100);
}
