extern int func_02021980(void *arg);
extern int func_01ff80a8(void);
extern void func_020219b4(void *arg, int adj);

int func_0202223c(void *arg) {
    int adj = func_02021980(arg) * 2;
    if (adj != 0) adj += func_01ff80a8();
    func_020219b4(arg, adj);
    return 0;
}
