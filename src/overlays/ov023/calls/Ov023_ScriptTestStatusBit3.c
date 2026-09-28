extern char data_ov023_0208a784[];
/* Return 1 if flag bit 3 is set in the VM status word (*(table+4))+0x8758c, else 0. */
int Ov023_ScriptTestStatusBit3(void) {
    if ((*(unsigned short *)(*(int *)(data_ov023_0208a784 + 4) + 0x8758c) & 8) != 0) {
        return 1;
    }
    return 0;
}
