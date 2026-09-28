/* Script-VM command handler (family skeleton: tools/gen_vm_emit.py).
 * Builder: Ov002_CreatePieceClass.
 *
 * One field is NOT fed by a fetcher: params.bField11 is a literal 0, stored
 * right after the last operand and before the target/id fetches. The generator
 * cannot see fields like that -- it only knows about slots written from a
 * fetcher's return value -- so it produced C that was 4 bytes short with every
 * instruction otherwise correct. Worth knowing for the rest of the family:
 * a small, otherwise-inexplicable size gap in a generated member is more likely
 * a constant-initialised field than a codegen problem.
 */
typedef struct {
    int nField00;            /* +0x00 */
    short nField04;          /* +0x04 */
    short nField06;          /* +0x06 */
    int nField08;            /* +0x08 */
    int nField0c;            /* +0x0c */
    unsigned char bField10;   /* +0x10 */
    unsigned char bField11;   /* +0x11 -- literal 0, not from a fetcher */
    short nField12;          /* +0x12 */
    short nField14;          /* +0x14 */
    short nField16;          /* +0x16 */
} Ov002EmitParams;          /* 0x18 */

extern int ByteCode_ResolveOperand(void *self, void *desc);
extern int ScriptVm_ReadOperandInt(void *self, void *desc);
extern int ScriptVm_ReadOperandFx32(void *self, void *desc);
extern int Ov002_CreatePieceClass(unsigned short id, Ov002EmitParams *params);
extern void Ov002_SetModuleSlot(int target, int value);

int Ov002_VmCmd7ceac(void *self, char *descs) {
    Ov002EmitParams params;
    int target;
    int id;

    params.nField00 = ByteCode_ResolveOperand(self, descs + 0x10);
    params.nField04 = ScriptVm_ReadOperandInt(self, descs + 0x18);
    params.nField06 = ScriptVm_ReadOperandInt(self, descs + 0x20);
    params.nField08 = ScriptVm_ReadOperandFx32(self, descs + 0x28);
    params.nField0c = ScriptVm_ReadOperandFx32(self, descs + 0x30);
    params.bField10 = ScriptVm_ReadOperandInt(self, descs + 0x38);
    params.nField12 = ScriptVm_ReadOperandFx32(self, descs + 0x40);
    params.nField14 = ScriptVm_ReadOperandFx32(self, descs + 0x48);
    params.nField16 = ScriptVm_ReadOperandFx32(self, descs + 0x50);
    params.bField11 = 0;
    target = ScriptVm_ReadOperandInt(self, descs);
    id = ScriptVm_ReadOperandInt(self, descs + 0x8);
    Ov002_SetModuleSlot(target, Ov002_CreatePieceClass((unsigned short)id, &params));
    return 1;
}
