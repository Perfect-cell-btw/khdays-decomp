/* Loads texture image data into texture VRAM (begin/load/end). */

extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *src, unsigned offset, unsigned size);
extern void GX_EndLoadTex(void);

void Gfd_LoadTexB(void *src, unsigned offset, unsigned size) {
    GX_BeginLoadTex();
    GX_LoadTex(src, offset, size);
    GX_EndLoadTex();
}
