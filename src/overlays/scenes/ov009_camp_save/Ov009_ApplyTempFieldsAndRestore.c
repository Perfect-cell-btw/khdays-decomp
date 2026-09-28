/* Runs the element's callback at a temporary position: moves it, invokes its tag-tracker callback
 * and moves it back. */

extern void Ov009_Elem_SetPos(void *context, void *entry, int arg2, int arg3);
extern void Ov009_TagTracker_InvokeCallback(void *context, void *entry);

void Ov009_ApplyTempFieldsAndRestore(void *context, void *entry, int arg2, int arg3)
{
    int x = *(short *)((char *)entry + 2);
    int y = *(short *)((char *)entry + 4);

    Ov009_Elem_SetPos(context, entry, arg2, arg3);
    Ov009_TagTracker_InvokeCallback(context, entry);
    Ov009_Elem_SetPos(context, entry, x, y);
}
