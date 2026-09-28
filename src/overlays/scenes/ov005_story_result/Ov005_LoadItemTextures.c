/* Loads the icon texture of every item and the special reward icons. */

typedef unsigned short u16;
typedef struct MsgDbItemRecord {char pad0[32];u16 icon;} MsgDbItemRecord;
typedef struct Ov005TextureResource {void *resource;unsigned int textureKey,paletteKey;} Ov005TextureResource;
typedef struct Ov005Context {char pad0[0x6154c];Ov005TextureResource textures[213];} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void MsgDb_FetchRecord(MsgDbItemRecord **,int,unsigned int,int);
extern void DispatchByNodeKind(MsgDbItemRecord **);
extern void Ov005_LoadTextureResource(Ov005TextureResource *,int);
static inline int GetIconIndex(MsgDbItemRecord *record) {
    if(!record || !record->icon)return 0;
    return record->icon-1;
}
void Ov005_LoadItemTextures(void) {
    MsgDbItemRecord *record=0;
    int itemId;
    int textureId;
    for(itemId=1;itemId<0x277;itemId++) {
        MsgDb_FetchRecord(&record,0x15,itemId,14);
        textureId=GetIconIndex(record);
        Ov005_LoadTextureResource(&data_ov005_0205b80c->textures[textureId],textureId);
        if(record)DispatchByNodeKind(&record);
    }
    for(itemId=0xd1;itemId<0xd5;itemId++)Ov005_LoadTextureResource(&data_ov005_0205b80c->textures[itemId],itemId);
}
