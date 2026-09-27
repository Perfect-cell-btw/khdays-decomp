extern int func_ov026_0208b188(void);
extern void func_020362ec(void *image);
extern void func_ov026_02085aa4(void);
extern void func_ov026_0208a774(void);
extern void func_ov026_0208cb0c(void);
extern char *data_ov026_02091368[];

void *func_ov026_0208c598(void)
{
    void *result;

    if (func_ov026_0208b188() != 0) {
        result = func_ov026_0208cb0c;
    } else {
        result = 0;
    }

    func_020362ec(data_ov026_02091368[0] + 0xc0fc);
    func_ov026_02085aa4();
    func_ov026_0208a774();

    return result;
}
