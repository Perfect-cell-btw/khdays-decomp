#include "game/class_descriptor.h"
/* ov000 class descriptor data_ov000_0205a9c0, 0x0205a9c0-0x0205a9d4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 0204d630, method 0204dbb4, 0x507c-byte state.
 */

extern void Ov000_TitleInit(void);
extern void Ov000_TeardownTitleScene(void);

GameClassDescriptor data_ov000_0205a9c0 = {
    8,  /* nClassId */
    15,  /* nGroupId */
    Ov000_TitleInit,  /* pfnCtor */
    Ov000_TeardownTitleScene,  /* pfnMethod */
    20604,  /* nAuxSize */
    0,  /* pArena */
};
