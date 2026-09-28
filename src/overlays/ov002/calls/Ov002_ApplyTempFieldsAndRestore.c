extern void Ov002_Elem_SetPos(void *context, void *entry, int arg2, int arg3);
extern void Ov002_TagTracker_InvokeCallback(void *context, void *entry);

void Ov002_ApplyTempFieldsAndRestore(void *context, void *entry, int arg2, int arg3)
{
    int x = *(short *)((char *)entry + 2);
    int y = *(short *)((char *)entry + 4);

    Ov002_Elem_SetPos(context, entry, arg2, arg3);
    Ov002_TagTracker_InvokeCallback(context, entry);
    Ov002_Elem_SetPos(context, entry, x, y);
}
