/* Script-VM command handler, eleven operands into a 0x20 block.
 * Builder: Ov015_CreatePickupClass.
 *
 * TWO optional operands here (type tags at descs+0x18 and descs+0x20), each a
 * ternary so both arms share one store. Note also that params.bField1c -- the
 * HIGHEST offset in the block -- is written THIRD, right after the target/count
 * fetches; the field order in the struct and the assignment order in the source
 * are independent, and following the ROM's assignment order is what matters.
 *
 * `nCount` truncates at the assignment (lsls/lsrs straight into r6) because the tag
 * tests intervene between its fetch and its use.
 */

#include "game/engine.h"

typedef struct {
    int nField00;            /* +0x00 */
    int nField04;            /* +0x04 */
    int nField08;            /* +0x08 */
    unsigned char bField0c;  /* +0x0c */
    char pad0d[1];
    short nField0e;          /* +0x0e */
    short nField10;          /* +0x10 */
    short nField12;          /* +0x12 */
    unsigned char bField14;  /* +0x14 */
    char pad15[3];
    int nField18;            /* +0x18 */
    unsigned char bField1c;  /* +0x1c */
    char pad1d[3];
} Ov015EmitParams;           /* 0x20 */

extern int Ov015_CreatePickupClass(int nCount, Ov015EmitParams *params);
extern void Ov002_SetModuleSlot(int target, int value);

int Ov015_VmCmd22b0(void *self, char *descs) {
    Ov015EmitParams params;
    int target;
    unsigned short nCount;

    target = ScriptVm_ReadOperandInt(self, descs);
    nCount = ScriptVm_ReadOperandInt(self, descs + 0x8);
    params.bField1c = ScriptVm_ReadOperandInt(self, descs + 0x10);
    params.nField00 = (*(short *)(descs + 0x18) == 0)
                      ? 0 : ByteCode_ResolveOperand(self, descs + 0x18);
    params.nField04 = (*(short *)(descs + 0x20) == 0)
                      ? 0 : ByteCode_ResolveOperand(self, descs + 0x20);
    params.nField08 = ScriptVm_ReadOperandFx32(self, descs + 0x28);
    params.bField0c = ScriptVm_ReadOperandInt(self, descs + 0x30);
    params.nField0e = ScriptVm_ReadOperandFx32(self, descs + 0x38);
    params.nField10 = ScriptVm_ReadOperandFx32(self, descs + 0x40);
    params.nField12 = ScriptVm_ReadOperandFx32(self, descs + 0x48);
    params.bField14 = ScriptVm_ReadOperandInt(self, descs + 0x50);
    params.nField18 = ScriptVm_ReadOperandInt(self, descs + 0x58);
    Ov002_SetModuleSlot(target, Ov015_CreatePickupClass(nCount, &params));
    return 1;
}
