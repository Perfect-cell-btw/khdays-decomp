extern int SND_RegisterSeq(void *name, int mode);
extern void InstallHandlerPairByFlag(int a);
extern int ResSlot_Acquire(int h, int a);
extern int Obj_GetIndirectWord(int h, int kind);
extern int Archive_GetMember(int h, int kind, int index);
extern void Tex0_GetTexPlttParams(char *dst, int src, int a);
extern void ResSlot_Release(int h);
extern int gOv002MoPrizePackPath;
extern char *data_ov002_0207fa28;

/* Loads the shop's item table out of the archive: opens it, walks the seven-kind entry list and
 * copies each record into the 8-byte slots at +0x60. */
void Ov002_LoadShopTable(void) {
    int arc = SND_RegisterSeq(&gOv002MoPrizePackPath, 4);
    int list;
    int count;
    int i;
    int off;
    InstallHandlerPairByFlag(0);
    list = ResSlot_Acquire(arc, 1);
    InstallHandlerPairByFlag(1);
    count = Obj_GetIndirectWord(list, 7);
    i = 0;
    if (count > 0) {
        off = i;
        do {
            Tex0_GetTexPlttParams((&data_ov002_0207fa28)[1] + 0x60 + off,
                          Archive_GetMember(list, 7, i), 0);
            i++;
            off += 8;
        } while (i < count);
    }
    ResSlot_Release(arc);
}
