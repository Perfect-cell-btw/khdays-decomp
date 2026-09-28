extern int Obj_SetTransition();
extern int Render_ReleaseNodeItem();

void Ov002_Piece_ReleaseRenderItem(int arg0) {
    Obj_SetTransition(arg0 + 0x1c, 0, 0);
    Render_ReleaseNodeItem(arg0 + 0x1c);
}
