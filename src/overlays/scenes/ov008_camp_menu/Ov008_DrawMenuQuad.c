/* Draws a textured menu quad with the 3D engine (dimmed or full colour), offset by the draw origin.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;

typedef struct Ov008TextureParams {
    u32 texImageParam;
    u32 texPlttBase;
} Ov008TextureParams;

typedef struct Ov008MenuQuad {
    Ov008TextureParams texture;
    s16 x, y, z, width, height, u, v, texWidth, texHeight, alpha, polygonId;
    s16 reserved;
    int dimmed;
} Ov008MenuQuad;

typedef struct Ov008DrawOrigin {
    s16 x, y;
} Ov008DrawOrigin;

extern Ov008DrawOrigin data_ov008_02090f18;
extern void GX_SendFifoWords(u32 command, const void *words, u32 count);

static inline void color(u32 rgb) {
    GX_SendFifoWords(0x20, &rgb, 1);
}
static inline void polygon(u32 lights, u32 mode, u32 cull, u32 polygonId, u32 alpha, u32 misc) {
    u32 attrs = lights | (mode << 4) | (cull << 6) |
                (polygonId << 24) | (alpha << 16) | misc;
    GX_SendFifoWords(0x29, &attrs, 1);
}
static inline void begin(u32 primitive) {
    GX_SendFifoWords(0x40, &primitive, 1);
}
static inline void texcoord(s16 u, s16 v) {
    u32 packet = (u16)u | ((u32)(u16)v << 16);
    GX_SendFifoWords(0x22, &packet, 1);
}
static inline void vertex(s16 x, s16 y, s16 z) {
    u32 packet[2];
    packet[0] = (u16)x | ((u32)(u16)y << 16);
    packet[1] = (u16)z;
    GX_SendFifoWords(0x23, packet, 2);
}

void Ov008_DrawMenuQuad(Ov008MenuQuad *quad) {
    int x, y;
    s16 z;
    if (quad->dimmed) color(0x294a);
    else color(0x7fff);
    GX_SendFifoWords(0x2b2a, &quad->texture, 2);
    polygon(0, 0, 3, quad->polygonId, quad->alpha, 0);
    begin(1);
    x = quad->x - data_ov008_02090f18.x - 128;
    y = quad->y - data_ov008_02090f18.y - 96;
    z = quad->z;
    texcoord(quad->u << 4, quad->v << 4);
    vertex(x << 6, y << 6, z << 6);
    texcoord((quad->u + quad->texWidth) << 4, quad->v << 4);
    vertex((x + quad->width) << 6, y << 6, z << 6);
    texcoord((quad->u + quad->texWidth) << 4,
             (quad->v + quad->texHeight) << 4);
    vertex((x + quad->width) << 6, (y + quad->height) << 6, z << 6);
    texcoord(quad->u << 4, (quad->v + quad->texHeight) << 4);
    vertex(x << 6, (y + quad->height) << 6, z << 6);
    GX_SendFifoWords(0x41, 0, 0);
}
