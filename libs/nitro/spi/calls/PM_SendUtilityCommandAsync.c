extern int PMi_Lock(void);
extern void PMi_SendPxiData(unsigned int cmd);

struct CC {
    char _0[0x20];
    int field_20;
    int field_24;
};
extern struct CC data_020463cc;

int PM_SendUtilityCommandAsync(unsigned int arg0, int arg1, int arg2)
{
    if (PMi_Lock() == 0) return 1;
    data_020463cc.field_20 = arg1;
    data_020463cc.field_24 = arg2;
    PMi_SendPxiData(((arg0 >> 16) & 0xff) | 0x02006300);
    PMi_SendPxiData(0x01010000 | (arg0 & 0xffff));
    return 0;
}
