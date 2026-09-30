#include "game/class_descriptor.h"
/* ov076 class descriptor gOv076LarxeneClass, 0x020b9c74-0x020b9c88 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b813c, 0x2e54-byte state.
 */

extern void Ov076_CreateTaggedObjectHandler46Cf(void);
extern void Ov076_initSubitemsClear(void);

GameClassDescriptor gOv076LarxeneClass = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov076_CreateTaggedObjectHandler46Cf,  /* pfnCtor */
    Ov076_initSubitemsClear,  /* pfnMethod */
    11860,  /* nAuxSize */
    0,  /* pArena */
};
