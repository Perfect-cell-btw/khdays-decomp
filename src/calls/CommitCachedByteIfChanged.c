/* Re-read the current value via ScriptVm_ReadOperandInt and, if it differs from the byte
 * cached at data_020425e8, commit the change: when bit 8 of LoadGlobalU16At0() is
 * set play sound 0x40 first, then store the new byte and notify SetSelectionIfChanged.
 * Always reports success. */
extern int data_020425e8;

extern int ScriptVm_ReadOperandInt(void *arg);
extern int LoadGlobalU16At0(void);
extern void InvokeSubStructAndStampByte(int a, int b);
extern void SetSelectionIfChanged(int v);

int CommitCachedByteIfChanged(void *arg) {
    int v = ScriptVm_ReadOperandInt(arg);

    if (v != *(signed char *)&data_020425e8) {
        if ((LoadGlobalU16At0() & 0x100) != 0) {
            InvokeSubStructAndStampByte(0x40, 0);
        }
        *(char *)&data_020425e8 = v;
        SetSelectionIfChanged((unsigned char)v);
    }

    return 1;
}
