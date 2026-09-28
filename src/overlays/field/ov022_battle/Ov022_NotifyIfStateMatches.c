/* When the object belongs to the local player's side and is active, sets its model's polygon id and
 * posts its update. */

extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int state);
extern void NNS_G3dMdlSetMdlPolygonID(int a, int b, int c);
extern void func_ov022_0208ffe8(int a);

struct Sel0208b374 { unsigned char sel : 3; };

void Ov022_NotifyIfStateMatches(int arg0, int arg1, int arg2) {
    unsigned char *pb = *(unsigned char **)(arg0 + 0x148);
    unsigned int mode = *(unsigned char *)(arg0 + 0x14c);
    int neg;
    if (mode == 0 || mode == 4) return;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) !=
        ((struct Sel0208b374 *)(arg0 + 0x14d))->sel) return;
    neg = -1;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == neg) return;
    if (*pb >= 6 && *pb <= 8 && *(unsigned char *)(arg0 + 0x14c) == 1) return;
    NNS_G3dMdlSetMdlPolygonID(*(int *)(arg0 + 0x94), arg1, arg2);
    func_ov022_0208ffe8(arg0 + 0x1c);
}
