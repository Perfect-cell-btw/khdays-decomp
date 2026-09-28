/* Maps the sub BG/OBJ VRAM banks and enables the sub engine's 1D OBJ mapping. */

extern int GX_SetBankForSubBG();
extern int GX_SetBankForSubOBJ();

void Ov001_SetupSubScreenBanks(void) {
    volatile unsigned int *p;

    GX_SetBankForSubBG(0x180);
    GX_SetBankForSubOBJ(8);
    p = (volatile unsigned int *)0x04001000;
    *p = (*p & 0xffcfffefu) | 0x10u | 0x200000u;
}
