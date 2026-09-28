/* Ov023_CmdPlaceObject -- Ov023_CmdPlaceObject: script command that places one of the scene's
 * model objects (Ov023_PlaceObject 02083afc).  Operand 1 is the object's index, 2 / 3 its
 * position and 4 / 5 its angles in degrees; operand 0, when given, names the resource to start
 * it on.  Returns 1. */
typedef unsigned char  u8;
typedef signed short   s16;

typedef struct Ov023Operand {
    s16  nType;               /* 0x00 */
    u8   pad_02[6];
} Ov023Operand;               /* 0x08 */

extern int   ScriptVm_ReadOperandInt(void *pCtx, Ov023Operand *pOperand);     /* ScriptVm_ReadOperandInt */
extern char *ByteCode_ResolveOperand(void *pCtx, Ov023Operand *pOperand);     /* ScriptVm_ReadOperandString */
extern void  Ov023_PlaceObject(const char *pszResource, int nIndex, int nX, int nY, int nAngleA, int nAngleB); /* Ov023_PlaceObject */

int Ov023_CmdPlaceObject(void *pCtx, Ov023Operand *pOperand)
{
    int nIndex;
    int nX;
    int nY;
    int nAngleA;
    int nAngleB;

    nIndex = ScriptVm_ReadOperandInt(pCtx, pOperand + 1);
    nX = ScriptVm_ReadOperandInt(pCtx, pOperand + 2);
    nY = ScriptVm_ReadOperandInt(pCtx, pOperand + 3);
    nAngleA = ScriptVm_ReadOperandInt(pCtx, pOperand + 4);
    nAngleB = ScriptVm_ReadOperandInt(pCtx, pOperand + 5);
    if (pOperand->nType != 0) {
        Ov023_PlaceObject(ByteCode_ResolveOperand(pCtx, pOperand), nIndex, nX, nY, nAngleA, nAngleB);
    } else {
        Ov023_PlaceObject(0, nIndex, nX, nY, nAngleA, nAngleB);
    }
    return 1;
}
