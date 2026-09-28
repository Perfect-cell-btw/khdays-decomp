/* Script-VM command: resolve an entry by (id, param) and push a signed fx value to it.
 *
 * Reads three operands -- a u8 id, a u16 param, and an fx32 -- then resolves the target entry with
 * Ov002_List_ScaleEntryTag(id, param) and applies (short)fx via Ov002_ElementSetFade(entry, 1, v). The
 * middle operand is NOT discarded (Ghidra dropped it): it is the second argument to the resolver.
 */

extern int ScriptVm_ReadOperandInt(int self, unsigned short *operand);
extern int ScriptVm_ReadOperandFx32(int self, unsigned short *operand);
extern void *Ov002_List_ScaleEntryTag(int id, int param);
extern void Ov002_ElementSetFade(void *entry, int a, short value);

int Ov002_VmSetEntryValue(int self, unsigned short *op) {
    int id = ScriptVm_ReadOperandInt(self, op);
    int param = ScriptVm_ReadOperandInt(self, op + 4);
    int value = ScriptVm_ReadOperandFx32(self, op + 8);

    Ov002_ElementSetFade(
        Ov002_List_ScaleEntryTag((unsigned char)id, (unsigned short)param), 1,
        (short)value);
    return 1;
}
