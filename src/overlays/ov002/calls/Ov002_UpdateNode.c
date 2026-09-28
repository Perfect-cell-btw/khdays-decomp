typedef void (*Ov002NodeStep)(int pNode);

extern void Ov002_DetachEntry(int pNode);
extern void Ov002_Element_Deactivate(int pNode);
extern void Ov002_UnlinkNode(int pNode);
extern void Ov002_ClearHalfwordAt0x12(int pNode);

/* Run one update pass over the node, skipping it entirely while it is
 * inactive. The two optional stages are gated on their own flag bits, then
 * the fixed stage runs, the class step is invoked if present, and the node
 * is committed. */
void Ov002_UpdateNode(int pNode)
{
    Ov002NodeStep pfnStep;

    if ((*(unsigned short *)(pNode + 0x12) & 1) == 0) {
        return;
    }

    if ((*(unsigned short *)(pNode + 0x12) & 4) != 0) {
        Ov002_DetachEntry(pNode);
    }

    if ((*(unsigned short *)(pNode + 0x12) & 2) != 0) {
        Ov002_Element_Deactivate(pNode);
    }

    Ov002_UnlinkNode(pNode);

    pfnStep = *(Ov002NodeStep *)(*(int *)(pNode + 8) + 4);
    if (pfnStep != 0) {
        pfnStep(pNode);
    }

    Ov002_ClearHalfwordAt0x12(pNode);
}
