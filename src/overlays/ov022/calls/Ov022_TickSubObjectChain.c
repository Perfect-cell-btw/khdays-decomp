extern void func_ov022_0209093c(short *p, int a, int b);
extern void Ov022_DropGroundMark(int obj);
extern int Ov022_IsBit0Set(void *p);
extern void func_ov022_02092844(void *p);
extern int Ov022_IsBit0Set_3(void *p);
extern void Ov022_TearDownNode(void *p);
extern int Ov022_IsBit0Set_5(void *p);
extern void func_ov022_020942c4(void *p);
extern int Ov022_IsBit0Set_4(void *p);
extern void func_ov022_02093400(void *p);
extern void Ov022_RefreshDirtyPanels(int p);
extern void Ov022_DrawChargeEntries(int obj);
extern void func_ov022_0209d3a0(int obj);

struct Obj020a0710 { char pad[0x464]; unsigned long long flags464; };
struct Bit694 { unsigned char lo1 : 1; };

void Ov022_TickSubObjectChain(int obj, int param2, int param3, int param4) {
    func_ov022_0209093c((short *)(obj + 0x2288), param2, param3);
    if ((*(unsigned long long *)obj & 0x200LL) != 0) return;
    if (((struct Bit694 *)(obj + 0x694))->lo1) {
        Ov022_DropGroundMark(obj);
        if (Ov022_IsBit0Set((void *)(obj + 0x1070))) func_ov022_02092844((void *)(obj + 0x1070));
        if (Ov022_IsBit0Set_3((void *)(obj + 0x1198))) Ov022_TearDownNode((void *)(obj + 0x1198));
        if (Ov022_IsBit0Set_5((void *)(obj + 0x1c8c))) func_ov022_020942c4((void *)(obj + 0x1c8c));
        if (Ov022_IsBit0Set_4((void *)(obj + 0x1318)) &&
            (((struct Obj020a0710 *)obj)->flags464 & 0x80LL) != 0)
            func_ov022_02093400((void *)(obj + 0x1318));
        Ov022_RefreshDirtyPanels(obj + 0x1da8);
        Ov022_DrawChargeEntries(obj);
        func_ov022_0209d3a0(obj);
    }
}
