/* Ov022_PollBattleEntry -- battle-scene poll: decide whether to advance to the 02082c54 step.
 * Two paths, chosen by bit 2 of the scene's flags halfword:
 *  - set: ask GetWordAt0x58c about the sub-object at +0x2c and then run the "any player"
 *    (-1) input check; on success run the transition hook.
 *  - clear: close the current panel and run the input check for either the local player
 *    (QueryActiveStateOrDelegate) or any player, depending on bit 2 of data_0204c240.
 * Returns the next step function, or 0 to stay.
 *
 * data_0204c240 is read as a BYTE (ldrb). The `arg = -1` arm is written second so it stays
 * out of line: the ROM reuses the `movs r0,#4` mask register and reaches -1 with
 * `subs r0,r0,#5`, which only happens when that arm is the branch target. */

#include "game/engine.h"

extern int Ov002_RefreshEntries(int arg0);
extern void Ov002_RebuildSeatSetRows(void);
extern void Ov022_UpdateCameraAndViews(int arg0);
extern int data_ov022_020b2e60;
extern void func_ov022_02082c54(void);
extern unsigned char data_0204c240;

int Ov022_PollBattleEntry(void) {
    int ret = 0;
    if ((*(unsigned short *)*(int *)&data_ov022_020b2e60 & 4) != 0) {
        if (GetWordAt0x58c(*(int *)(*(int *)&data_ov022_020b2e60 + 0x2c)) != 0 &&
            Ov002_RefreshEntries(-1) != 0) {
            ret = (int)func_ov022_02082c54;
            Ov002_RebuildSeatSetRows();
        }
    } else {
        int arg;
        Ov022_UpdateCameraAndViews(0);
        if ((data_0204c240 & 4) != 0) {
            arg = QueryActiveStateOrDelegate();
        } else {
            arg = -1;
        }
        if (Ov002_RefreshEntries(arg) != 0) {
            ret = (int)func_ov022_02082c54;
        }
    }
    return ret;
}
