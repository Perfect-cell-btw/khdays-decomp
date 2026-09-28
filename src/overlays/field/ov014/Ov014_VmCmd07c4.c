/* Script-VM command handler (see tools/gen_vm_emit.py for the family skeleton),
 * with one wrinkle the pure members do not have: the first operand is OPTIONAL.
 *
 * Each descriptor starts with a 16-bit type tag, and tag 0 means "absent" -- so
 * this command reads the tag at descs+0x10 directly and substitutes 0 rather
 * than calling the fetcher. It must be a ternary, not an if/else: the ROM shares
 * ONE store between both arms, and an if/else emits two.
 *
 * Note also that `id` is declared `unsigned short` here where the pure members
 * need `int` plus a cast at the call. Both spellings are right in their place --
 * mwcc truncates where you write the conversion, so when code intervenes between
 * the fetch and the use (the conditional, here) the ROM truncates at the
 * assignment, and when the fetch is adjacent to the use it truncates there.
 */
typedef struct {
    int nField00;            /* +0x00 */
    int nField04;            /* +0x04 */
    int nField08;            /* +0x08 */
} Ov014EmitParams;           /* 0xc */

extern int ByteCode_ResolveOperand(void *self, void *desc);
extern int ScriptVm_ReadOperandInt(void *self, void *desc);
extern int ScriptVm_ReadOperandFx32(void *self, void *desc);
extern int Ov014_Instantiate(int id, Ov014EmitParams *params);
extern void Ov002_SetModuleSlot(int target, int value);

int Ov014_VmCmd07c4(void *self, char *descs) {
    Ov014EmitParams params;
    int target;
    unsigned short id;

    target = ScriptVm_ReadOperandInt(self, descs);
    id = ScriptVm_ReadOperandInt(self, descs + 0x8);
    params.nField00 = (*(short *)(descs + 0x10) == 0)
                      ? 0 : ByteCode_ResolveOperand(self, descs + 0x10);
    params.nField04 = ScriptVm_ReadOperandFx32(self, descs + 0x18);
    params.nField08 = ScriptVm_ReadOperandFx32(self, descs + 0x20);
    Ov002_SetModuleSlot(target, Ov014_Instantiate(id, &params));
    return 1;
}
