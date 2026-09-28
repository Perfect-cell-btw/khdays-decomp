/* Run Ov009_TickTagTrackerNodes, then if the +0x2c pending bit is set run Ov009_ResolveHoveredEntryAndNotify. */
extern void Ov009_TickTagTrackerNodes(int self);
extern void Ov009_ResolveHoveredEntryAndNotify(int self);
struct pend { unsigned char b0 : 1; };
void Ov009_TickSelectionWidget(int param_1) {
    Ov009_TickTagTrackerNodes(param_1);
    if (((struct pend *)(param_1 + 0x2c))->b0)
        Ov009_ResolveHoveredEntryAndNotify(param_1);
}
