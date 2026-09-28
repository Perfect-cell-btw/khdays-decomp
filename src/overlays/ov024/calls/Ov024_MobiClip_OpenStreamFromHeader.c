/* Ov024_MobiClip_OpenStreamFromHeader -- MobiClip: open a stream from a parsed header on the stack.
 * Builds the decoder's header copy in a local (Ov024_MobiClip_InitFromHeader derives the active picture
 * size and crop from it) and hands both to TileTextRenderer_Init to start the stream. */
extern void Ov024_MobiClip_InitFromHeader(int ctx, unsigned short *dst, unsigned short *src);
extern void TileTextRenderer_Init(unsigned int *ctx, int a, unsigned int b, unsigned short *hdr);

void Ov024_MobiClip_OpenStreamFromHeader(unsigned int *ctx, int a, unsigned int b, unsigned short *src) {
    unsigned short hdr[8];
    Ov024_MobiClip_InitFromHeader((int)ctx, hdr, src);
    TileTextRenderer_Init(ctx, a, b, hdr);
}
