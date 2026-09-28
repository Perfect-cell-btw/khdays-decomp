#include "game/class_descriptor.h"
/* ov005 class descriptor data_ov005_0205b4f0, 0x0205b4f0-0x0205b504 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02053b80, method 02053c58, 0x62198-byte state.
 */

extern void Ov005_EnterMainScene(void);
extern void Ov005_CloseMainMenu(void);

GameClassDescriptor data_ov005_0205b4f0 = {
    8,  /* nClassId */
    14,  /* nGroupId */
    Ov005_EnterMainScene,  /* pfnCtor */
    Ov005_CloseMainMenu,  /* pfnMethod */
    401816,  /* nAuxSize */
    0,  /* pArena */
};
