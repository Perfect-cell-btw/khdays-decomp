extern void ReleaseField74AndCleanup();
extern void Ov022_ClearByte();
void Ov022_TeardownIfBit0(unsigned char *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    if ((*arg0 & 1) != 0) {
        ReleaseField74AndCleanup((int)(arg0 + 4), (unsigned int)*arg0, arg2, arg3);
        Ov022_ClearByte(arg0);
    }
}
