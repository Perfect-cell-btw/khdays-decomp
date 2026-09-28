/* Whether bit 5 of the root context's flag byte at +0x8b68 is set. */

extern int data_ov002_0207fa00;

int Ov002_GetRootField8b68Alt(void) {
    return (*(unsigned char *)(*(int *)&data_ov002_0207fa00 + 0x8b68) & 0x20) != 0;
}
