/* Return the address of the three-word cue request block at +0x9740 of the ov008 context. */

extern int data_ov008_02090f04[];
int Ov008_GetCueRequest(void)
{
    return data_ov008_02090f04[1] + 0x9740;
}
