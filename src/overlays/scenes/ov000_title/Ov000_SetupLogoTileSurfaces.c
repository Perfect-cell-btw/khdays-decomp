/* Prepares the logo scene's three tile surfaces: copies three TileSurfaceCfg templates, clears the
 * BG3 scroll map, points each config at the resource storage and the BG3 VRAM target, applies each
 * via TileSurface_InitAndUpload4bpp, and arms the three surface slots with
 * Ov000_DispatchLogoAction(i, 2). */

typedef unsigned char  u8;
typedef unsigned int u32;

typedef struct TileSurfaceCfg {
    u8 unknown_00[0x18];
    void *pVramTarget;
    u32 nUnk1c;
    void *pPixels;
    u32 unknown_24;
} TileSurfaceCfg;

typedef struct Ov000LogoSceneContext {
    u8 pad_0000[0x4af8];
    u8 resourceStorage[8];
    void *resource;
    u8 surface0[0x3c];
    u8 surface1[0x3c];
    u8 surface2[0x3c];
    u8 pad_4bb8[0];
    u8 variantObject[0x0c];
} Ov000LogoSceneContext;

extern const TileSurfaceCfg data_ov000_0205a8d4;
extern const TileSurfaceCfg data_ov000_0205a884;
extern const TileSurfaceCfg data_ov000_0205a8ac;
extern const u8 data_ov000_0205ab38[];
extern Ov000LogoSceneContext *volatile data_ov000_0205ac28;

extern void StreamReader_InitU16(void *resource, void *sharedResource);
extern void Ov000_InitResourceRecord(void *object, const void *config);
extern void *G2S_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *destination, u32 size);
extern void TileSurface_InitAndUpload4bpp(void *surface, const TileSurfaceCfg *config);
extern void Ov000_DispatchLogoAction(int selector, int argument);

void Ov000_SetupLogoTileSurfaces(void) {
    TileSurfaceCfg config2 = data_ov000_0205a8d4;
    Ov000LogoSceneContext *context = data_ov000_0205ac28;
    TileSurfaceCfg config1 = data_ov000_0205a884;
    TileSurfaceCfg config0 = data_ov000_0205a8ac;

    StreamReader_InitU16(context->resourceStorage, context->resource);
    Ov000_InitResourceRecord(data_ov000_0205ac28->variantObject,
                        data_ov000_0205ab38);
    MIi_CpuClearFast(0, G2S_GetBG3ScrPtr(), 0x800);

    config2.pPixels = data_ov000_0205ac28->resourceStorage;
    config2.pVramTarget = G2S_GetBG3ScrPtr();
    config1.pPixels = data_ov000_0205ac28->resourceStorage;
    config1.pVramTarget = G2S_GetBG3ScrPtr();
    config0.pPixels = data_ov000_0205ac28->resourceStorage;
    config0.pVramTarget = G2S_GetBG3ScrPtr();

    TileSurface_InitAndUpload4bpp(data_ov000_0205ac28->surface0, &config2);
    TileSurface_InitAndUpload4bpp(data_ov000_0205ac28->surface1, &config1);
    TileSurface_InitAndUpload4bpp(data_ov000_0205ac28->surface2, &config0);

    Ov000_DispatchLogoAction(0, 2);
    Ov000_DispatchLogoAction(1, 2);
    Ov000_DispatchLogoAction(2, 2);
}
