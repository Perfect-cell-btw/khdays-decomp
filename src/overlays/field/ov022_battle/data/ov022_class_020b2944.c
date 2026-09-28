#include "game/class_descriptor.h"
/* ov022 class descriptor data_ov022_020b2944, 0x020b2944-0x020b2958 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02089654, method 020896dc, 0xd8-byte state.
 */

extern void Ov022_SetupPauseMenu(void);
extern void func_ov022_020896dc(void);

GameClassDescriptor data_ov022_020b2944 = {
    14,  /* nClassId */
    6,  /* nGroupId */
    Ov022_SetupPauseMenu,  /* pfnCtor */
    func_ov022_020896dc,  /* pfnMethod */
    216,  /* nAuxSize */
    0,  /* pArena */
};
