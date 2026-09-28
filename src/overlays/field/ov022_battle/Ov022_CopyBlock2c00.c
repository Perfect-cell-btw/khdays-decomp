/* Clears 32 bytes at +0x2c00. */

extern void MIi_CpuClearFast();
void Ov022_CopyBlock2c00(int arg0) {
    MIi_CpuClearFast(0, arg0 + 0x2c00, 0x20);
}
