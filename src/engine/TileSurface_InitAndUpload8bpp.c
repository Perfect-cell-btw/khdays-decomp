/* Initialises a tile surface in a fixed bit depth (and uploads it), forwarding to TileSurface_Init.
 */

extern int TileSurface_Init();

int TileSurface_InitAndUpload8bpp(void *pA, void *pB) {
    int a = (int)pA;
    int b = (int)pB;
    return TileSurface_Init(a, b, 1, 1);
}
