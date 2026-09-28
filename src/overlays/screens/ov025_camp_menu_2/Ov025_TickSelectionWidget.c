/* Run Ov025_TickTagTrackerNodes, then if the +0x2c pending bit is set run Ov025_ResolveHoveredEntryAndNotify. */
extern void Ov025_TickTagTrackerNodes(int self);
extern void Ov025_ResolveHoveredEntryAndNotify(int self);
struct pend { unsigned char b0 : 1; };
void Ov025_TickSelectionWidget(int param_1) {
    Ov025_TickTagTrackerNodes(param_1);
    if (((struct pend *)(param_1 + 0x2c))->b0)
        Ov025_ResolveHoveredEntryAndNotify(param_1);
}
