/* Initialises a tile text renderer with the size taken from a MobiClip header. */

extern void Ov012_MobiClip_InitFromHeader();
extern void TileTextRenderer_Init();

void Ov012_InitOpeningRendererFromMobiClipHeader(int this_, int arg1, int arg2, int arg3) {
    int buf[4];
    Ov012_MobiClip_InitFromHeader(this_, buf, arg3);
    TileTextRenderer_Init(this_, arg1, arg2, (int)buf);
}
