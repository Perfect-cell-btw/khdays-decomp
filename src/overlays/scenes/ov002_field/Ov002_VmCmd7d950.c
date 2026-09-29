/* Script-VM command handler, twelve operands into a 0x1c block.
 * Builder: Ov002_CreateTravelClass.
 *
 * Hand-written rather than generated, and it needed no iteration because it is
 * two already-known wrinkles stacked:
 *   - the first operand is OPTIONAL (16-bit type tag at descs+0x10, 0 = absent),
 *     which must be a ternary so both arms share one store;
 *   - `nCount` is truncated at the ASSIGNMENT here (lsls/lsrs straight into r6),
 *     because the tag test intervenes between the fetch and the use.
 * See tools/gen_vm_emit.py and the family notes for both.
 */

#include "game/engine.h"

typedef struct {
    int nField00;            /* +0x00 */
    int nField04;            /* +0x04 */
    unsigned char bField08;  /* +0x08 */
    char pad09[1];
    short nField0a;          /* +0x0a */
    short nField0c;          /* +0x0c */
    short nField0e;          /* +0x0e */
    short nField10;          /* +0x10 */
    short nField12;          /* +0x12 */
    unsigned char bField14;  /* +0x14 */
    char pad15[1];
    short nField16;          /* +0x16 */
    short nField18;          /* +0x18 */
    unsigned char bField1a;  /* +0x1a */
    char pad1b[1];
} Ov002EmitParams1c;         /* 0x1c */

extern int Ov002_CreateTravelClass(int nCount, Ov002EmitParams1c *params);
extern void Ov002_SetModuleSlot(int target, int value);

int Ov002_VmCmd7d950(void *self, char *descs) {
    Ov002EmitParams1c params;
    int target;
    unsigned short nCount;

    target = ScriptVm_ReadOperandInt(self, descs);
    nCount = ScriptVm_ReadOperandInt(self, descs + 0x8);
    params.nField00 = (*(short *)(descs + 0x10) == 0)
                      ? 0 : ByteCode_ResolveOperand(self, descs + 0x10);
    params.nField04 = ScriptVm_ReadOperandFx32(self, descs + 0x18);
    params.bField08 = ScriptVm_ReadOperandInt(self, descs + 0x20);
    params.nField0a = ScriptVm_ReadOperandFx32(self, descs + 0x28);
    params.nField0c = ScriptVm_ReadOperandFx32(self, descs + 0x30);
    params.nField0e = ScriptVm_ReadOperandFx32(self, descs + 0x38);
    params.nField10 = ScriptVm_ReadOperandInt(self, descs + 0x40);
    params.nField12 = ScriptVm_ReadOperandInt(self, descs + 0x48);
    params.bField14 = ScriptVm_ReadOperandInt(self, descs + 0x50);
    params.nField16 = ScriptVm_ReadOperandInt(self, descs + 0x58);
    params.nField18 = ScriptVm_ReadOperandInt(self, descs + 0x60);
    params.bField1a = ScriptVm_ReadOperandInt(self, descs + 0x68);
    Ov002_SetModuleSlot(target, Ov002_CreateTravelClass(nCount, &params));
    return 1;
}
