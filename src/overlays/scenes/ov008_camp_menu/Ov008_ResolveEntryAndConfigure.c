/* Finds a layout entry by id, pushes its sub-item set (when hiding) and sets its slots' visibility.
 */

extern void *Ov008_FindEntryById(void *arg0, void *arg1, int arg2);
extern void Ov008_PushSubitemSet(void *arg0, void *arg1, int arg2);
extern void Ov008_SetEntrySlotsVisible(void *arg0, void *arg1, int arg2);

void Ov008_ResolveEntryAndConfigure(void *arg0, void *arg1, int arg2)
{
    void *value = Ov008_FindEntryById(arg0, arg1, arg2);

    Ov008_PushSubitemSet(arg0, value, arg2 == 0);
    Ov008_SetEntrySlotsVisible(arg0, value, arg2);
}
