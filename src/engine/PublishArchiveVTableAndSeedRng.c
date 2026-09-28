extern void Sbc_Nop(void);
extern void Sbc_Ret(void);
extern void func_01ffba90(void);
extern void NNSi_G3dSbcCmdSetPolygonAttr(void);
extern void NNSi_G3dFuncSbcMAT(void);
extern void func_01ffc0d0(void);
extern void NNSi_G3dFuncSbcNODEDESC(void);
extern void NNSi_G3dFuncSbc_BB(void);
extern void NNSi_G3dFuncSbc_BBY(void);
extern void NNSi_G3dFuncSbcNODEMIX(void);
extern void Sbc_CallDl(void);
extern void func_01ffcbac(void);
extern void NNSi_G3dFuncSbc_ENVMAP(void);
extern void NNSi_G3dFuncSbc_PRJMAP(void);
extern void func_02016284(unsigned seed);
extern void *data_027e0660[];

/* Publishes the archive backend's 14-entry vtable and seeds the RNG. */
void PublishArchiveVTableAndSeedRng(void) {
    data_027e0660[0] = (void *)&Sbc_Nop;
    data_027e0660[1] = (void *)&Sbc_Ret;
    data_027e0660[2] = (void *)&func_01ffba90;
    data_027e0660[3] = (void *)&NNSi_G3dSbcCmdSetPolygonAttr;
    data_027e0660[4] = (void *)&NNSi_G3dFuncSbcMAT;
    data_027e0660[5] = (void *)&func_01ffc0d0;
    data_027e0660[6] = (void *)&NNSi_G3dFuncSbcNODEDESC;
    data_027e0660[7] = (void *)&NNSi_G3dFuncSbc_BB;
    data_027e0660[8] = (void *)&NNSi_G3dFuncSbc_BBY;
    data_027e0660[9] = (void *)&NNSi_G3dFuncSbcNODEMIX;
    data_027e0660[10] = (void *)&Sbc_CallDl;
    data_027e0660[11] = (void *)&func_01ffcbac;
    data_027e0660[12] = (void *)&NNSi_G3dFuncSbc_ENVMAP;
    data_027e0660[13] = (void *)&NNSi_G3dFuncSbc_PRJMAP;
    func_02016284(1);
}
