/* Returns the configured slot of a code. */

extern int Ov025_LookupSlotConfig();

int Ov025_LookupEntry(int arg0) {
    return Ov025_LookupSlotConfig(arg0, 0);
}
