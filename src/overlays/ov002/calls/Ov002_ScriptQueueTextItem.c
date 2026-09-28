/* The four halfword parameters a kind-one text item carries. */
typedef struct Ov002FieldOpParam {
    unsigned short nFieldOffset;        /* +0x0 */
    unsigned short nFieldWidth;         /* +0x2 */
    short nOp;                          /* +0x4 */
    unsigned short nOperand;            /* +0x6 */
} Ov002FieldOpParam;

extern int ScriptVm_ReadOperandInt(int pCtx, unsigned short *pOperand);
extern int ByteCode_ResolveOperand(int pCtx, unsigned short *pOperand);
extern void Ov002_QueueTextItem(int bMain, int nFlags, int nX, int nY,
                                int nStyle, int nKind, void *pParam);

/* Script command: queue one text item.
 *
 * The first five operands give the screen selector, the item flags, the two
 * coordinates and the style. The sixth operand's tag then chooses the payload:
 * tag zero resolves a single value and queues it as kind zero, while tag four
 * builds a field-op descriptor - the offset and width unpacked from that
 * operand's own second word, the operator and its operand read from the two
 * operands after it - and queues that as kind one. Any other tag queues
 * nothing. Always returns one.
 */
int Ov002_ScriptQueueTextItem(int pCtx, unsigned short *pArgs)
{
    int nValue;
    unsigned short *pTagged;
    Ov002FieldOpParam fieldOp;
    int nSubScreen;
    int nFlags;
    int nX;
    int nStyle;
    int nY;

    nSubScreen = ScriptVm_ReadOperandInt(pCtx, pArgs);
    nFlags = ScriptVm_ReadOperandInt(pCtx, pArgs + 4);
    nX = ScriptVm_ReadOperandInt(pCtx, pArgs + 8);
    nStyle = ScriptVm_ReadOperandInt(pCtx, pArgs + 0x18);
    nY = ScriptVm_ReadOperandInt(pCtx, pArgs + 0x1c);

    if (*(short *)(pArgs + 0xc) == 0) {
        nValue = ByteCode_ResolveOperand(pCtx, pArgs + 0x10);
        Ov002_QueueTextItem(nSubScreen == 0, nFlags, nX, nY, nStyle, 0,
                            &nValue);
    } else if (*(short *)(pArgs + 0xc) == 4) {
        pTagged = pArgs + 0xc;
        fieldOp.nFieldOffset = (unsigned short)*(int *)(pTagged + 2);
        fieldOp.nFieldWidth =
            (unsigned short)((unsigned int)*(int *)(pTagged + 2) >> 16);
        fieldOp.nOp = (short)ScriptVm_ReadOperandInt(pCtx, pArgs + 0x10);
        fieldOp.nOperand = (unsigned short)ScriptVm_ReadOperandInt(pCtx, pArgs + 0x14);
        Ov002_QueueTextItem(nSubScreen == 0, nFlags, nX, nY, nStyle, 1,
                            &fieldOp);
    }
    return 1;
}
