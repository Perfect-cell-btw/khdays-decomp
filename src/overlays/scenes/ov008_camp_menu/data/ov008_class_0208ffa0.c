#include "game/class_descriptor.h"
/* ov008 class descriptor data_ov008_0208ffa0, 0x0208ffa0-0x0208ffb4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  This one is the campaign menu scene (constructor 0204db2c, 0x5050-byte state).
 */

extern void Ov008_MainMenuInit(void);
extern void Ov008_MainMenuExit(void);

GameClassDescriptor data_ov008_0208ffa0 = {
    8,  /* nClassId */
    14,  /* nGroupId */
    Ov008_MainMenuInit,  /* pfnCtor */
    Ov008_MainMenuExit,  /* pfnMethod */
    20560,  /* nAuxSize */
    0,  /* pArena */
};
