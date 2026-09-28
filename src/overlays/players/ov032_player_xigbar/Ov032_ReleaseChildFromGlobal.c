extern int ReleaseField74AndCleanup(int);
extern int data_ov032_020b58c0;

int Ov032_ReleaseChildFromGlobal(void) {
    return ReleaseField74AndCleanup(data_ov032_020b58c0 + 0x2e84);
}
