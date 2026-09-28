extern char *data_ov008_02090f04[];
extern void Ov008_SetCtxField95cc(int arg0);
extern void Ov008_BlitConfigRegion(int arg0, int arg1);
extern void Ov008_EnableBothHalves(int arg0);

void Ov008_SetGlobalConfigAndInit(int value)
{
    *(int *)(data_ov008_02090f04[1] + 0x95c8) = value;
    Ov008_SetCtxField95cc(7);
    Ov008_BlitConfigRegion(-0x10, 0x64);
    Ov008_EnableBothHalves(0);
}
