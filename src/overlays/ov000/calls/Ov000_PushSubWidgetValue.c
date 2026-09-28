/* Ov000_PushSubWidgetValue -- push a value to the logo scene's sub-widget, ov000. Reads
 * the current selection (Ov000_FindEntryById over the widget @scene+0x4c) and applies
 * `value` to it via Ov000_SetEntrySlotsVisible. */
extern char *data_ov000_0205ac24;
extern int  Ov000_FindEntryById(void *widget, int count);
extern void Ov000_SetEntrySlotsVisible(void *widget, int sel, int value);
void Ov000_PushSubWidgetValue(int value) {
    char *base = data_ov000_0205ac24;
    int sel = Ov000_FindEntryById(base + 0x4c, 0x3c);
    Ov000_SetEntrySlotsVisible(base + 0x4c, sel, value);
}
