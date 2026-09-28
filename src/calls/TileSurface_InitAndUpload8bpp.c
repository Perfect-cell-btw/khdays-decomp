extern int TileSurface_Init();

int TileSurface_InitAndUpload8bpp(int a, int b) {
    return TileSurface_Init(a, b, 1, 1);
}
