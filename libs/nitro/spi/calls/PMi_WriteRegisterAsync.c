/* NitroSDK spi (pm.c): PMi_WriteRegisterAsync -- PXI command 0x64 (PM_REG_WRITE), two packets. */
extern int PMi_Lock(void);
extern void PMi_SendPxiData(unsigned int cmd);

struct CC {
    char _0[0x20];
    int field_20;
    int field_24;
};
extern struct CC data_020463cc;

int PMi_WriteRegisterAsync(int arg0, int arg1, int arg2, int arg3)
{
    if (PMi_Lock() == 0) return 1;
    data_020463cc.field_20 = arg2;
    data_020463cc.field_24 = arg3;
    PMi_SendPxiData((arg0 & 0xff) | 0x02006400);
    PMi_SendPxiData(0x01010000 | (arg1 & 0xffff));
    return 0;
}
