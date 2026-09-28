/* End the active key-sharing session (if any) and mark the handle slot free. */
extern void func_02023ad0(int handle);
extern int data_ov002_0207f00c;

void Ov002_Roster_Release(void) {
    int handle = *(int *)&data_ov002_0207f00c;
    if (handle != -1) {
        func_02023ad0(handle);
        *(int *)&data_ov002_0207f00c = -1;
    }
}
