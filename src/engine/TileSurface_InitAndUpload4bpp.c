/* Initialises a tile surface in a fixed bit depth (and uploads it), forwarding to TileSurface_Init.
 */

extern int TileSurface_Init();

int TileSurface_InitAndUpload4bpp(int a, int b) {
    return TileSurface_Init(a, b, 1, 0);
}
