/* Run Ov006_TickTagTrackerNodes, then if the +0x2c pending bit is set run Ov006_ResolveHoveredEntryAndNotify. */
extern void Ov006_TickTagTrackerNodes(int self);
extern void Ov006_ResolveHoveredEntryAndNotify(int self);
struct pend { unsigned char b0 : 1; };
void Ov006_TickSelectionWidget(int param_1) {
    Ov006_TickTagTrackerNodes(param_1);
    if (((struct pend *)(param_1 + 0x2c))->b0)
        Ov006_ResolveHoveredEntryAndNotify(param_1);
}
