extern void func_02023ad0(int handle);
extern char *data_ov026_02091360;
/* Close the session's key-sharing handle (ctx+8) when a session exists. */
void Ov026_CloseKeySharing(void) {
    int ctx = (int)data_ov026_02091360;
    if (ctx == 0) {
        return;
    }
    func_02023ad0(*(int *)(ctx + 8));
}
