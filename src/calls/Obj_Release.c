extern void Slot_UnlinkAll(void *);
extern void SlotNodeList_FreeAll(void *);

int Obj_Release(void *object)
{
    Slot_UnlinkAll(object);
    SlotNodeList_FreeAll(object);
    return 1;
}
