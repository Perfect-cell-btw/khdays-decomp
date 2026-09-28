/* Returns the Nth zero-count entry of page A's list. */

extern int Ov025_GetPageA();
extern int Ov025_NthZeroCountNode();

int Ov025_GetNextMissionEntry_2(int arg0) {
    return Ov025_NthZeroCountNode(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
