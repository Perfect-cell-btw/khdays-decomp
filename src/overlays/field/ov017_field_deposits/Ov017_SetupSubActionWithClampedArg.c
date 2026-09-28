extern int Ov002_GetCtxTableByte();
extern void Render_SubmitNode();

void Ov017_SetupSubActionWithClampedArg(int this_) {
    int r = Ov002_GetCtxTableByte(*(unsigned char *)(this_ + 0x10));
    Render_SubmitNode(this_ + 0x2c, (unsigned short)r, 0, 0);
}
