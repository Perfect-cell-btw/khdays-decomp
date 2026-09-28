extern int Anim_GetFrame(int a, int b);
extern void Ov002_WidgetScrollCommit(int a, int b, int c, int d);
extern void func_ov022_020ad588(int this_);

void Ov060_SetupAndForwardToVecBuilder(int this_) {
    int r = Anim_GetFrame(*(int *)(this_ + 0x20) + 4, 0);
    Ov002_WidgetScrollCommit(this_ + 0xf0c, this_ + 0x2c30, *(short *)(this_ + 0x2aba), r);
    func_ov022_020ad588(this_);
}
