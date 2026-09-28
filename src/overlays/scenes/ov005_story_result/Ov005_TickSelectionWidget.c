/* Run Ov005_TickTagTrackerNodes, then if the +0x2c pending bit is set run Ov005_ResolveHoveredEntryAndNotify. */
extern void Ov005_TickTagTrackerNodes(int self);
extern void Ov005_ResolveHoveredEntryAndNotify(int self);
struct pend { unsigned char b0 : 1; };
void Ov005_TickSelectionWidget(int param_1) {
    Ov005_TickTagTrackerNodes(param_1);
    if (((struct pend *)(param_1 + 0x2c))->b0)
        Ov005_ResolveHoveredEntryAndNotify(param_1);
}
