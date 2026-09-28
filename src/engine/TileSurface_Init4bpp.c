extern int TileSurface_Init();

int TileSurface_Init4bpp(int a, int b)
{
    return TileSurface_Init(a, b, 0, 0);
}
