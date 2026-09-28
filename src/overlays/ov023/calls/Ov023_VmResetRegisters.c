/* Ov023_VmResetRegisters -- reset the script VM's 0x100-byte register block and re-arm the command.
 * The block starts at +0x4a4 of the VM state (+0x128 of the caller's object). Clearing it,
 * running Ov023_CmdShowCharacterPanel and re-arming with Slot48_StoreAtCurrentIndex always reports 0 (command not
 * finished). */
extern void INITi_CpuClear32_0x01ff86fc(int value, void *dst, int size);
extern void Ov023_CmdShowCharacterPanel(int a, int b);
extern void Slot48_StoreAtCurrentIndex(int a, int b);

int Ov023_VmResetRegisters(int a, int b) {
    INITi_CpuClear32_0x01ff86fc(0, (void *)(*(int *)(a + 0x128) + 0x4a4), 0x100);
    Ov023_CmdShowCharacterPanel(a, b);
    Slot48_StoreAtCurrentIndex(a, b);
    return 0;
}
