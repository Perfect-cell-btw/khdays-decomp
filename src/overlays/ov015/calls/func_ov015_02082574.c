#pragma thumb on
/* func_ov015_02082574 -- Ov015_ScriptOpCreateSpots: script op that reads a target, a slot and
 * a table count, then per table its id and entry count and per entry the id, key, kind and
 * four link bytes (one operand each) followed by the kind's payload: a point (kind 0) or a
 * link (kind 1) carries a position (three fx32), the link also its link table and id; a
 * pickup (kind 2) carries a key byte and a halfword resolved to the pickup piece (ov002
 * 0207679c).  The entries are gathered in a 128-entry stack array, the tables in a spec
 * block handed to Ov015_CreateSpotClass (02080df8) on the slot, and the class table is
 * stored on the target (ov002 0207643c).  Always consumes the op (1). */
typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct VecFx32 { int x, y, z; } VecFx32;

typedef struct Ov015SpotEntry {
    s8  nId;                  /* 0x00 */
    s8  nKey;                 /* 0x01 */
    s8  nKind;                /* 0x02: 0 point, 1 link, 2 pickup */
    s8  aLink[4];             /* 0x03 */
    u8  pad_07;
    union {
        void *pPickup;        /* 0x08: pickup piece (kind 2) */
        VecFx32 position;     /* 0x08: point / link position */
    } u;
    s8  nLinkTable;           /* 0x14 */
    s8  nLinkId;              /* 0x15 */
    u8  pad_16[2];
} Ov015SpotEntry;

typedef struct Ov015SpotSpecRow {
    s8  nTable;               /* 0x00 */
    s8  nCount;               /* 0x01 */
    u8  pad_02[2];
    Ov015SpotEntry *aEntry;   /* 0x04 */
} Ov015SpotSpecRow;

typedef struct Ov015SpotSpec {
    s8  nRows;                /* 0x00 */
    u8  pad_01[3];
    Ov015SpotSpecRow aRow[9]; /* 0x04 */
} Ov015SpotSpec;

extern int   func_02021980(int vm, u16 *pc);            /* ScriptVm_ReadOperandInt */
extern int   func_02021994(int vm, u16 *pc);            /* ScriptVm_ReadOperandFx32 */
extern void *func_ov002_0207679c(u8 nKey, u16 nArg);    /* resolve a pickup piece */
extern void *func_ov015_02080df8(u16 nSlot, Ov015SpotSpec *pSpec); /* Ov015_CreateSpotClass */
extern void  func_ov002_0207643c(int nTarget, void *pValue);       /* store on the target */

#pragma push
#pragma opt_dead_assignments off
int func_ov015_02082574(int vm, u16 *pc)
{
    Ov015SpotSpec spec;
    Ov015SpotEntry aEntry[128];
    int nArg;
    int nKey;
    int nBase = 0;
    int i;
    int nTarget;
    int nSlot;
    u16 *pOperand;
    int j;

    nTarget = func_02021980(vm, pc);
    nSlot = func_02021980(vm, pc + 4);
    pOperand = pc + 8;
    pc += 0xc;
    spec.nRows = func_02021980(vm, pOperand);
    for (i = 0; i < spec.nRows; i++) {
        spec.aRow[i].nTable = func_02021980(vm, pc);
        pOperand = pc + 4;
        pc += 8;
        spec.aRow[i].nCount = func_02021980(vm, pOperand);
        spec.aRow[i].aEntry = &aEntry[nBase];
        j = 0;
        if (spec.aRow[i].nCount > 0) {
            for (; j < spec.aRow[i].nCount; j++, nBase++) {
                aEntry[nBase].nId = func_02021980(vm, pc);
                aEntry[nBase].nKey = func_02021980(vm, pc + 4);
                aEntry[nBase].nKind = func_02021980(vm, pc + 8);
                aEntry[nBase].aLink[0] = func_02021980(vm, pc + 0xc);
                aEntry[nBase].aLink[1] = func_02021980(vm, pc + 0x10);
                aEntry[nBase].aLink[2] = func_02021980(vm, pc + 0x14);
                pOperand = pc + 0x18;
                pc += 0x1c;
                aEntry[nBase].aLink[3] = func_02021980(vm, pOperand);
                switch (aEntry[nBase].nKind) {
                case 0:
                    aEntry[nBase].u.position.x = func_02021994(vm, pc);
                    aEntry[nBase].u.position.y = func_02021994(vm, pc + 4);
                    pOperand = pc + 8;
                    pc += 0xc;
                    aEntry[nBase].u.position.z = func_02021994(vm, pOperand);
                    break;
                case 1:
                    aEntry[nBase].u.position.x = func_02021994(vm, pc);
                    aEntry[nBase].u.position.y = func_02021994(vm, pc + 4);
                    aEntry[nBase].u.position.z = func_02021994(vm, pc + 8);
                    aEntry[nBase].nLinkTable = func_02021980(vm, pc + 0xc);
                    pOperand = pc + 0x10;
                    pc += 0x14;
                    aEntry[nBase].nLinkId = func_02021980(vm, pOperand);
                    break;
                case 2:
                    nKey = func_02021980(vm, pc);
                    pOperand = pc + 4;
                    pc += 8;
                    nArg = func_02021980(vm, pOperand);
                    aEntry[nBase].u.pPickup = func_ov002_0207679c(nKey, nArg);
                    break;
                }
            }
        }
    }
    func_ov002_0207643c(nTarget, func_ov015_02080df8(nSlot, &spec));
    return 1;
}
#pragma pop
