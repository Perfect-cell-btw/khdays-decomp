extern int ReleaseNodeResources();

void Ov002_Line_ReleaseNode(int arg0) {
    int n = *(int *)(arg0 + 8);
    if (*(signed char *)(n + 0x58) != 0) {
        ReleaseNodeResources(arg0 + 0x2c);
    }
}
