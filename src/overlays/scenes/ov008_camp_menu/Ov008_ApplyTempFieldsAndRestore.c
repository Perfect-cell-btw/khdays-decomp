/* Runs the element's callback at a temporary position: moves it, invokes its tag-tracker callback
 * and moves it back. */

extern void Ov008_Elem_SetPos(void *context, void *entry, int arg2, int arg3);
extern void Ov008_TagTracker_InvokeCallback(void *context, void *entry);

void Ov008_ApplyTempFieldsAndRestore(void *context, void *entry, int arg2, int arg3)
{
    int x = *(short *)((char *)entry + 2);
    int y = *(short *)((char *)entry + 4);

    Ov008_Elem_SetPos(context, entry, arg2, arg3);
    Ov008_TagTracker_InvokeCallback(context, entry);
    Ov008_Elem_SetPos(context, entry, x, y);
}
