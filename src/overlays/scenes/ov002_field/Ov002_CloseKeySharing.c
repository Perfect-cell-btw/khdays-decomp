extern void func_02023ad0(int handle);
extern void Ov002_World_ClearPending(void);
extern char *data_ov002_0207fa00;
/* Close the key-sharing session held at rootCtx+0x8d10 (if any) and run the follow-up. */
void Ov002_CloseKeySharing(void) {
    int handle = *(int *)((int)data_ov002_0207fa00 + 0x8d10);
    if (handle != -1) {
        func_02023ad0(handle);
        Ov002_World_ClearPending();
    }
}
