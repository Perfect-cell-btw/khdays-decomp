#include "game/class_descriptor.h"
/* ov098 class descriptor data_ov098_020bbce0, 0x020bbce0-0x020bbcf4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x3490-byte state.
 */

extern void Ov098_stateCtorReturnHandler(void);
extern void Ov098_setupTriple(void);

GameClassDescriptor data_ov098_020bbce0 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov098_stateCtorReturnHandler,  /* pfnCtor */
    Ov098_setupTriple,  /* pfnMethod */
    13456,  /* nAuxSize */
    0,  /* pArena */
};
