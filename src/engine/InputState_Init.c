/* Clears the input state words and the 0x30-byte input buffer; returns 1. */

extern void INITi_CpuClear32_0x01ff86fc(unsigned int data, void *dst, unsigned int size);
extern unsigned short gPadHeld[];
extern int gPadPressTimes[];

int InputState_Init(void)
{
    gPadHeld[1] = 0;
    gPadHeld[2] = 0;
    gPadHeld[0] = 0;
    INITi_CpuClear32_0x01ff86fc(0, gPadPressTimes, 0x30);
    return 1;
}
