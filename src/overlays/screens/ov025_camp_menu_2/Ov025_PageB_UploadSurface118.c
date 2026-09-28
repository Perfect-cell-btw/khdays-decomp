/* Uploads page B's surface +0x118 when page B is active. */

extern int Ov025_GetPageB();
extern int EnqueueObjGfxCommand();
extern int data_ov025_020b575c;

void Ov025_PageB_UploadSurface118(int arg0) {
    int x = Ov025_GetPageB(arg0);
    if (data_ov025_020b575c == 0) {
        return;
    }
    EnqueueObjGfxCommand(x + 0x118);
}
