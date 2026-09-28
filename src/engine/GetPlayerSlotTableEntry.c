/* Return a pointer to entry `idx` (stride 0x48) of the global table data_0204c500, or 0 if idx is
 * outside [0,2). */

extern char data_0204c500[];
int GetPlayerSlotTableEntry(int idx) {
    if (idx < 0 || idx >= 2) {
        return 0;
    }
    return (int)(data_0204c500 + idx * 0x48);
}
