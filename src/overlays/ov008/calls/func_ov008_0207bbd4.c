extern char *data_ov008_02090f24;
extern int func_01ff8128(void);

void func_ov008_0207bbd4(int value)
{
    *(unsigned char *)(data_ov008_02090f24 + 0x42a) = value;

    if (func_01ff8128() == 0) {
        *(unsigned char *)(data_ov008_02090f24 + func_01ff8128() + 0x48e) = value;
    }
}
