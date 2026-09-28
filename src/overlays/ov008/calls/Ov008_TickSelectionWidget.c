/* Per-frame tick of the ov000 selection widget. Ticks the widget's tag-tracker node list, then,
 * only if bit 0 of the byte at +0x2c is set, runs ResolveHoveredEntryAndNotify to update which
 * entry the cursor is over and fire the change notification. Tail of Ov000_TickPageScroll. */

extern void Ov008_TickTagTrackerNodes(void *);
extern void Ov008_ResolveHoveredEntryAndNotify(void *);
struct ov008_020554e4_flags {
    unsigned char _pad[0x2c];
    unsigned char flag : 1;
};

void Ov008_TickSelectionWidget(char *obj)
{
    Ov008_TickTagTrackerNodes(obj);
    if (((struct ov008_020554e4_flags *)obj)->flag != 0) {
        Ov008_ResolveHoveredEntryAndNotify(obj);
    }
}
