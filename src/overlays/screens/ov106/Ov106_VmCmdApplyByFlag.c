/* Script-VM command: fetch four operands and route to one of two handlers on the
 * fourth. Byte-identical twin of Ov023_VmCmdApplyByFlag -- same code, same relocs,
 * so the same command exists in both overlays and both call the SAME pair of
 * handlers (one living in ov023, one in ov106).
 *
 * The first operand is biased by -0x10 before use, which is why it is computed
 * into a local rather than passed inline.
 */

#include "game/engine.h"

extern void Ov023_PushTween(int a, int b, int c);
extern void Ov106_PushTransitionTarget(int a, int b);

int Ov106_VmCmdApplyByFlag(void *self, char *descs) {
    int base;
    int arg;
    int extra;

    base = ScriptVm_ReadOperandInt(self, descs) - 0x10;
    arg = ScriptVm_ReadOperandInt(self, descs + 0x8);
    extra = ScriptVm_ReadOperandInt(self, descs + 0x10);
    if (ScriptVm_ReadOperandInt(self, descs + 0x18) == 0) {
        Ov023_PushTween(extra, base, arg);
    } else {
        Ov106_PushTransitionTarget(base, arg);
    }
    return 1;
}
