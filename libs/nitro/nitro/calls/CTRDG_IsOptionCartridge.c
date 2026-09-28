/* True only when a cartridge is present and it is NOT an AGB game pak.  The two failure
 * paths share one `return 0`, so the first one has to reach it with a goto. */
extern int CTRDG_IsExisting(void);
extern int CTRDGi_IsAgbCartridgeAtInit(void);

int CTRDG_IsOptionCartridge(void) {
    if (CTRDG_IsExisting() == 0) {
        goto no;
    }
    if (CTRDGi_IsAgbCartridgeAtInit() == 0) {
        return 1;
    }
no:
    return 0;
}
