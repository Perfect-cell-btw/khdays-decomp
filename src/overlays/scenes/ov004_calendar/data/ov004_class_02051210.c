#include "game/class_descriptor.h"
/* ov004 class descriptor data_ov004_02051210, 0x02051210-0x02051224 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 0204fa44, method 0204fc98, 0x8-byte state.
 */

extern void Ov004_CreateMissionSelectScene(void);
extern void Ov004_ClassTeardown(void);

GameClassDescriptor data_ov004_02051210 = {
    8,  /* nClassId */
    15,  /* nGroupId */
    Ov004_CreateMissionSelectScene,  /* pfnCtor */
    Ov004_ClassTeardown,  /* pfnMethod */
    8,  /* nAuxSize */
    0,  /* pArena */
};
