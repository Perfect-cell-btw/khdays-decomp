/* Returns the mission screen's flag byte for the current value. */

extern char *data_ov008_02090f24;
extern int func_01ff8128(void);

int Ov008_GetMissionScreenFlag(void)
{
    return (unsigned char)*(data_ov008_02090f24 + func_01ff8128() + 0x48e);
}
