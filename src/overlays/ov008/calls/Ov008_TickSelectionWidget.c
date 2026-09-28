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
