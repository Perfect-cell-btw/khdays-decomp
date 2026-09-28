extern int ByteCode_ResolveOperand(void *a, void *b);
extern void Ov012_StartOpeningMovie(int x);

int Ov012_StartOpeningMovieFromScriptArgs(void *arg1, char *arg2) {
    int v = 0;
    if (*(short *)(arg2 + 0) == 2) {
        v = ByteCode_ResolveOperand(arg1, arg2);
    }
    if (*(short *)(arg2 + 8) == 2) {
        ByteCode_ResolveOperand(arg1, arg2 + 8);
    }
    if (*(short *)(arg2 + 0x10) == 2) {
        ByteCode_ResolveOperand(arg1, arg2 + 0x10);
    }
    Ov012_StartOpeningMovie(v);
    return 1;
}
