/* Run Ov002_TickTagTrackerNodes(param_1); if bit0 of its flag byte (+0x2c) is now set,
 * also run Ov002_ResolveHoveredEntryAndNotify(param_1). A 1-bit bitfield reproduces the ROM's
 * lsl#31;lsrs#31 bit0 extraction (a plain & 1 becomes tst, an int shift becomes asr). */
extern void Ov002_TickTagTrackerNodes(int obj);
extern void Ov002_ResolveHoveredEntryAndNotify(int obj);

struct flag2c { unsigned char active : 1; };

void Ov002_TickSelectionWidget(int param_1) {
    Ov002_TickTagTrackerNodes(param_1);
    if (((struct flag2c *)(param_1 + 0x2c))->active) {
        Ov002_ResolveHoveredEntryAndNotify(param_1);
    }
}
