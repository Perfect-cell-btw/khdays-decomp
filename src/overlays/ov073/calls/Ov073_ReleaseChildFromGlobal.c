extern int ReleaseField74AndCleanup(int);
extern int data_ov073_020ba540;

int Ov073_ReleaseChildFromGlobal(void) {
    return ReleaseField74AndCleanup(data_ov073_020ba540 + 0x2d0c);
}
