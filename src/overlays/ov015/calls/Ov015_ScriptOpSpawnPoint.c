/* Ov015_ScriptOpSpawnPoint -- Ov015_ScriptOpSpawnPoint: script op that reads a slot, a kind, an
 * index, a packed field / bit pair (raw word at pc + 0x1c: low half the GameState field,
 * next byte its bit) and a facing (fx32), then spawns a point piece (02080fc0) on the
 * slot's class table (ov002 02076468).  Always consumes the op (1). */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  ScriptVm_ReadOperandInt(int vm, u16 *pc);            /* ScriptVm_ReadOperandInt */
extern int  ScriptVm_ReadOperandFx32(int vm, u16 *pc);            /* ScriptVm_ReadOperandFx32 */
extern int  Ov002_GetModuleSlot(int nSlot);            /* class table of a slot */
extern int  Ov015_SpawnSpot(int pTable, int nKind, int nIndex, int nField, u8 nBit, int nFacing);

int Ov015_ScriptOpSpawnPoint(int vm, u16 *pc)
{
    int nSlot = ScriptVm_ReadOperandInt(vm, pc);
    u32 nKind = ScriptVm_ReadOperandInt(vm, pc + 4);
    u32 nIndex = ScriptVm_ReadOperandInt(vm, pc + 8);
    u32 nFieldBit = *(u32 *)(pc + 0xe);
    u16 nBitHalf = nFieldBit >> 16;
    int nFacing = ScriptVm_ReadOperandFx32(vm, pc + 0x10);

    Ov015_SpawnSpot(Ov002_GetModuleSlot(nSlot), nKind & 0xffff, nIndex & 0xffff, nFieldBit & 0xffff, nBitHalf, nFacing);
    return 1;
}
