extern void Ov022_ReleaseResourceTables(int a);
extern void Ov022_TeardownIfBit0(int a);
extern void Ov022_ClearIfBit0(int a);
extern void func_ov022_020929dc(int a);
extern void func_ov022_02092e4c(int a);
extern void Ov022_TeardownIfBit0_2(int a);
extern void func_ov022_02090198(int a);
extern void Ov022_TeardownVoices(int a);
extern void func_ov022_02094c44(int a);

void Ov022_ReleaseAllSubsystems(int arg0) {
    Ov022_ReleaseResourceTables(arg0);
    Ov022_TeardownIfBit0(arg0 + 0x1070);
    Ov022_ClearIfBit0(arg0 + 0x118c);
    func_ov022_020929dc(arg0 + 0x1198);
    func_ov022_02092e4c(arg0 + 0x1318);
    Ov022_TeardownIfBit0_2(arg0 + 0x1c8c);
    func_ov022_02090198(arg0 + 0x2288);
    Ov022_TeardownVoices(arg0 + 0x1da8);
    func_ov022_02094c44(arg0 + 0x22f8);
}
