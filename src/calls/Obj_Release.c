/* Run the object's two teardown steps (Slot_UnlinkAll then SlotNodeList_FreeAll) and report
 * success. */

extern void Slot_UnlinkAll(void *);
extern void SlotNodeList_FreeAll(void *);

int Obj_Release(void *object)
{
    Slot_UnlinkAll(object);
    SlotNodeList_FreeAll(object);
    return 1;
}
