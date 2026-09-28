extern int data_ov008_02090f04[];
extern void Mem_ReadU16(void *);
void Ov008_ReadInputHeader(void)
{
    Mem_ReadU16((void *)(data_ov008_02090f04[1] + 0x963e));
}
