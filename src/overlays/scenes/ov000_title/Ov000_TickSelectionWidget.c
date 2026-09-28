/* Run 020561b4, then if the +0x2c pending bit is set run 02056354. */
extern void Ov000_TickTagTrackerNodes(int self);
extern void Ov000_ResolveHoveredEntryAndNotify(int self);
struct pend { unsigned char b0 : 1; };
void Ov000_TickSelectionWidget(int param_1) {
    Ov000_TickTagTrackerNodes(param_1);
    if (((struct pend *)(param_1 + 0x2c))->b0)
        Ov000_ResolveHoveredEntryAndNotify(param_1);
}
