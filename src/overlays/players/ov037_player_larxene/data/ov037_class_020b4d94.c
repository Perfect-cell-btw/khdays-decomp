#include "game/class_descriptor.h"
/* ov037 class descriptor gOv037LarxeneClass, 0x020b4d94-0x020b4da8 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b325c, 0x2e54-byte state.
 */

extern void Ov037_CreateTaggedObjectHandler46Cf(void);
extern void Ov037_initSubitemsClear(void);

GameClassDescriptor gOv037LarxeneClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov037_CreateTaggedObjectHandler46Cf,  /* pfnCtor */
    Ov037_initSubitemsClear,  /* pfnMethod */
    11860,  /* nAuxSize */
    0,  /* pArena */
};
