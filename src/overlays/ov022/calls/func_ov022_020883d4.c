extern int GetEntryField20ByIndex(int arg0);
extern void func_ov022_020a0f2c(int arg0, int arg1);
void func_ov022_020883d4(int arg0, int arg1) {
    int e = GetEntryField20ByIndex(arg0);
    if (e == 0) return;
    func_ov022_020a0f2c(e, arg1);
}
