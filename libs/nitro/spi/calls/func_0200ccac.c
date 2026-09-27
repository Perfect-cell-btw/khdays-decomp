extern int PMi_Lock(void);
extern void PMi_SendPxiData(unsigned int cmd);
extern int func_0200d3a4(int mode, int chan, int useTimeout, int useRoute);

/* PXI state block; only the two reserved words this function touches are
 * named here (see PMi_ReadRegisterAsync.c / func_0200cb40.c for the fields
 * established elsewhere in the same block). */
extern int data_020463cc[];

int func_0200ccac(unsigned int channel, unsigned int value)
{
    if (PMi_Lock() == 0) return 1;

    data_020463cc[1] = 0;
    PMi_SendPxiData(0x03006000);

    while (*(volatile int *)&data_020463cc[1] == 0) {}

    data_020463cc[1] = 0;
    data_020463cc[2] = 0;
    func_0200d3a4(0, 2, 0, 1);

    PMi_SendPxiData((channel & 0xff) | 0x02006100);
    PMi_SendPxiData(0x01010000 | (value & 0xffff));

    return 0;
}
