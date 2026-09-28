/*
 * Reload guard around an object's section-relocation dispatch: save the global
 * reentrancy flag data_020427f0, set it, relocate/dispatch pFile (the 'KAPH'
 * relocation path when tagged, or the plain post-load hook otherwise), restore
 * the flag, run the real load-finish handler ModelAnimSet_Bind, then clear the
 * handle at pSlot[3] and hand back the handler's result.
 *
 * Returning ModelAnimSet_Bind's result is what keeps r0 live to the epilogue, so
 * the trailing `pSlot[3] = 0` materialises its zero in r1; declared `void`,
 * mwcc puts that zero in r0. The sibling Snd_RegisterSeqAndBind (the other caller of
 * ModelAnimSet_Bind, already matched) likewise returns int.
 */

extern void Obj_RelocateSections(unsigned int *param_1, int param_2);
extern void G3dRes_DefaultSetup(unsigned int *pRes);
extern int ModelAnimSet_Bind(int a, int b, int c, int d);
extern int data_020427f0;

int Resource_BindFileToSlot(unsigned int *pSlot, int nNode, unsigned int *pFile, int nHeap)
{
    int save = data_020427f0;
    int result;
    data_020427f0 = 1;
    if (*pFile == 0x4850414b) {
        Obj_RelocateSections(pFile, 1);
    } else {
        G3dRes_DefaultSetup(pFile);
    }
    data_020427f0 = save;
    result = ModelAnimSet_Bind((int)pSlot, nNode, (int)pFile, nHeap);
    pSlot[3] = 0;
    return result;
}
