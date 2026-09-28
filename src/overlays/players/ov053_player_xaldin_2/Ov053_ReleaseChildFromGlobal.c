extern int ReleaseField74AndCleanup(int);
extern int data_ov053_020b7e60;

int Ov053_ReleaseChildFromGlobal(void) {
    return ReleaseField74AndCleanup(data_ov053_020b7e60 + 0x2d0c);
}
