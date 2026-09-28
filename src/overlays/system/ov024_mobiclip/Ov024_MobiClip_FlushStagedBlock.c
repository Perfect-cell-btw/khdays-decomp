/* Ov024_MobiClip_FlushStagedBlock -- MobiClip player: flush the staged palette/table block.
 * Tail-calls MIi_CpuCopy32 to push data_ov024_02093b20 to the destination and length parked
 * at +0xdc / +0xd8 of the player block. */
extern void MIi_CpuCopy32(const void *src, void *dst, unsigned int size);
extern int  data_ov024_0209ba48;
extern int  data_ov024_02093b20;

void Ov024_MobiClip_FlushStagedBlock(void) {
    MIi_CpuCopy32(&data_ov024_02093b20,
                  *(void **)((char *)&data_ov024_0209ba48 + 0xdc),
                  *(unsigned int *)((char *)&data_ov024_0209ba48 + 0xd8));
}
