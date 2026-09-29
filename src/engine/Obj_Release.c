/* Run the object's two teardown steps (Slot_UnlinkAll then SlotNodeList_FreeAll) and report
 * success. */

#include "game/engine.h"

int Obj_Release(void *object)
{
    Slot_UnlinkAll(object);
    SlotNodeList_FreeAll(object);
    return 1;
}
