/* Script-VM command handler (family skeleton: tools/gen_vm_emit.py).
 * Builder: Ov002_CreateActorClass.
 *
 * Seven operands into a 0x18 block whose middle is three consecutive SHORTS
 * (+0x04/+0x06/+0x08) followed by two words and a trailing byte -- the mixed
 * widths are what the generator reads off the str/strh/strb it sees, and they
 * are why the block is 0x18 rather than 0x1c despite having the same operand
 * count as the wider members. */
typedef struct {
    int nField00;            /* +0x00 */
    short nField04;          /* +0x04 */
    short nField06;          /* +0x06 */
    short nField08;          /* +0x08 */
    char pad0a[2];
    int nField0c;            /* +0x0c */
    int nField10;            /* +0x10 */
    unsigned char bField14;  /* +0x14 */
    char pad15[3];
} Ov002EmitParams18;         /* 0x18 */

extern int ByteCode_ResolveOperand(void *self, void *desc);
extern int ScriptVm_ReadOperandInt(void *self, void *desc);
extern int ScriptVm_ReadOperandFx32(void *self, void *desc);
extern int Ov002_CreateActorClass(int nCount, Ov002EmitParams18 *params);
extern void Ov002_SetModuleSlot(int target, int value);

int Ov002_VmCmd7d18c(void *self, char *descs) {
    Ov002EmitParams18 params;
    int target;
    int nCount;

    params.nField00 = ByteCode_ResolveOperand(self, descs + 0x10);
    params.nField04 = ScriptVm_ReadOperandInt(self, descs + 0x18);
    params.nField06 = ScriptVm_ReadOperandInt(self, descs + 0x20);
    params.nField08 = ScriptVm_ReadOperandInt(self, descs + 0x28);
    params.nField0c = ScriptVm_ReadOperandFx32(self, descs + 0x30);
    params.nField10 = ScriptVm_ReadOperandFx32(self, descs + 0x38);
    params.bField14 = ScriptVm_ReadOperandInt(self, descs + 0x40);
    target = ScriptVm_ReadOperandInt(self, descs);
    nCount = ScriptVm_ReadOperandInt(self, descs + 0x8);
    Ov002_SetModuleSlot(target, Ov002_CreateActorClass((unsigned short)nCount, &params));
    return 1;
}
