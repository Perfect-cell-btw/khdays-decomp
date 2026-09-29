/* Reads the input header halfword of the screen work area. Returns the halfword it reads. */

extern int data_ov008_02090f04[];
extern unsigned short Mem_ReadU16(void *);
unsigned short Ov008_ReadInputHeader(void)
{
    return Mem_ReadU16((void *)(data_ov008_02090f04[1] + 0x963e));
}
