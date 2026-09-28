/* Switch the help message, remembering which one is up.
 *
 * Asking for the mode that is already showing does nothing. Otherwise the current message is
 * dismissed with code 0x8f, and a non-negative mode looks its own code up in a halfword table and
 * shows that one; a negative mode means no help at all. Either way the mode is stored at 0x1bc of
 * the panel context, which Ghidra carries as nHelpMode.
 */

#include "nitro/types.h"

extern char *data_ov002_0207f614;
extern u16 data_ov002_0207db78[];
extern int Ov002_ForwardToSubDc(int code);
extern void Ov002_ForwardToSubDc_2(int handle);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int handle);

void Ov002_SetHelpMode(int mode) {
    char *ctx = data_ov002_0207f614;

    if (*(int *)(ctx + 0x1bc) == mode) {
        return;
    }
    Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x8f));
    if (mode >= 0) {
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(data_ov002_0207db78[mode]));
    }
    *(int *)(ctx + 0x1bc) = mode;
}
