/* Resolve four consecutive 8-byte descriptors (offsets 0, 8, 0x10, 0x18) through
 * ScriptVm_ReadOperandInt and hand the four results to Ov002_SetScriptRequest. Always
 * reports success. */

#include "game/engine.h"

extern void Ov002_SetScriptRequest(int a, int b, int c, int d);

int Ov002_ResolveFourDescriptors(void *self, char *descs) {
    int a = ScriptVm_ReadOperandInt(self, descs);
    int b = ScriptVm_ReadOperandInt(self, descs + 8);
    int c = ScriptVm_ReadOperandInt(self, descs + 0x10);
    int d = ScriptVm_ReadOperandInt(self, descs + 0x18);

    Ov002_SetScriptRequest(a, b, c, d);
    return 1;
}
