/* Releases the object service instance. */

extern void func_02023ad0();
extern int data_ov002_0207fa18;

void Ov002_ReleaseObjectService(void) {
    int p = *(int *)((char *)&data_ov002_0207fa18 + 4);
    if (p != 0) {
        func_02023ad0(p);
        *(int *)((char *)&data_ov002_0207fa18 + 4) = 0;
    }
}
