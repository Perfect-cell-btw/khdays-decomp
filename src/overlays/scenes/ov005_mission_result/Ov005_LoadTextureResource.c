/* Loads an icon texture from the archive into its reserved VRAM. */

typedef struct NNSG3dResFileHeader NNSG3dResFileHeader;
typedef struct NNSG3dResTex NNSG3dResTex;
typedef struct Ov005TextureResource {NNSG3dResFileHeader *resource;unsigned int textureKey,paletteKey;} Ov005TextureResource;
typedef struct Ov005Context {char pad0[0x61548];void *textureArchive;} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void InstallHandlerPairByFlag(int);
extern NNSG3dResFileHeader *Archive_GetMember(void *,int,int);
extern NNSG3dResTex *NNS_G3dGetTex(NNSG3dResFileHeader *);
extern void NNS_G3dTexSetTexKey(NNSG3dResTex *,unsigned int,unsigned int);
extern void NNSG2d_SetOamManExDrawOrderType(NNSG3dResTex *,unsigned int);
extern void Tex_LoadVram(NNSG3dResTex *);
extern void Gfx_UploadBlock(NNSG3dResTex *);
void Ov005_LoadTextureResource(Ov005TextureResource *entry,int textureId) {
    NNSG3dResTex *texture;
    InstallHandlerPairByFlag(0);
    entry->resource=Archive_GetMember(data_ov005_0205b80c->textureArchive,7,textureId);
    if(entry->resource) {
        texture=NNS_G3dGetTex(entry->resource);
        NNS_G3dTexSetTexKey(texture,entry->textureKey,0);
        NNSG2d_SetOamManExDrawOrderType(texture,entry->paletteKey);
        Tex_LoadVram(texture);
        Gfx_UploadBlock(texture);
    }
    InstallHandlerPairByFlag(1);
}
