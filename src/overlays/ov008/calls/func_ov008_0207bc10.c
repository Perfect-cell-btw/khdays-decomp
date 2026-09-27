extern char *data_ov008_02090f24;
extern int func_01ff8128(void);

int func_ov008_0207bc10(void)
{
    return (unsigned char)*(data_ov008_02090f24 + func_01ff8128() + 0x48e);
}
