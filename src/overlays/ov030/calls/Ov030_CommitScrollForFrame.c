extern int Anim_GetFrame();
extern int Ov002_WidgetScrollCommit();
extern int func_ov022_020ad588();

void Ov030_CommitScrollForFrame(int r0) {
    int a = Anim_GetFrame(*(int *)(r0 + 0x20) + 4, 0);
    Ov002_WidgetScrollCommit(r0 + 0xf0c, r0 + 0x2c54, *(short *)(r0 + 0x2aba), a);
    func_ov022_020ad588(r0);
}
