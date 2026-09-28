/* Return the address of the block embedded at +0x4a80 of the ov008 menu context -- that is, the
 * block immediately after the 0x4a80-byte subsystem object the context opens with (the one
 * Ov000_InitSubsystemObject constructs). */

extern int data_ov008_02090f04[];
int Ov008_GetCtxBlock4a80(void)
{
    return data_ov008_02090f04[1] + 0x4a80;
}
