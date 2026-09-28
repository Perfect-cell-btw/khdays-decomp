/* Run Ov026_TickTagTrackerNodes, then if the +0x2c pending bit is set run Ov026_ResolveHoveredEntryAndNotify. */
extern void Ov026_TickTagTrackerNodes(int self);
extern void Ov026_ResolveHoveredEntryAndNotify(int self);
struct pend { unsigned char b0 : 1; };
void Ov026_TickSelectionWidget(int param_1) {
    Ov026_TickTagTrackerNodes(param_1);
    if (((struct pend *)(param_1 + 0x2c))->b0)
        Ov026_ResolveHoveredEntryAndNotify(param_1);
}
