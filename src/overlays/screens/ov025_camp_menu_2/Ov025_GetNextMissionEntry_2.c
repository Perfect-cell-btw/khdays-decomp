extern int Ov025_GetPageA();
extern int Ov025_NthZeroCountNode();

void Ov025_GetNextMissionEntry_2(int arg0) {
    Ov025_NthZeroCountNode(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
