#include "game/class_descriptor.h"
/* ov093 class descriptor gOv093LarxeneClass, 0x020bc334-0x020bc348 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x2e54-byte state.
 */

extern void Ov093_CreateTaggedObjectHandler46Cf(void);
extern void Ov093_initSubitemsClear(void);

GameClassDescriptor gOv093LarxeneClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov093_CreateTaggedObjectHandler46Cf,  /* pfnCtor */
    Ov093_initSubitemsClear,  /* pfnMethod */
    11860,  /* nAuxSize */
    0,  /* pArena */
};
