/* Clears the input state words and the 0x30-byte input buffer; returns 1. */

extern void INITi_CpuClear32_0x01ff86fc(unsigned int data, void *dst, unsigned int size);
extern unsigned short data_0204c18c[];
extern int data_0204c194[];

int InputState_Init(void)
{
    data_0204c18c[1] = 0;
    data_0204c18c[2] = 0;
    data_0204c18c[0] = 0;
    INITi_CpuClear32_0x01ff86fc(0, data_0204c194, 0x30);
    return 1;
}
