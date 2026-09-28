/* Twin of Ov023_CmdSetGameMode2. */
extern void func_ov002_0206d31c(int arg);
extern void SetGameMode(int arg);
int Ov106_CmdSetGameMode2(int param_1) {
    func_ov002_0206d31c(param_1);
    SetGameMode(2);
    return 1;
}
