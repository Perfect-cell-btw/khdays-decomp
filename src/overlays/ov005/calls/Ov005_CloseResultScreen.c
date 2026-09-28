typedef unsigned char u8;
typedef struct Ov000ResourceTracker {char opaque[76];} Ov000ResourceTracker;
typedef struct Ov005SpriteManager {char opaque[0x4a80];} Ov005SpriteManager;
typedef struct FontInfo {char opaque[12];} FontInfo;
typedef struct TileSurface {char opaque[60];} TileSurface;
typedef struct Ov005TextTable {char opaque[12];} Ov005TextTable;
typedef struct Ov005ResultContext {
    void *resultArchive,*localizedResultArchive;
    Ov000ResourceTracker resourceTracker;
    Ov005SpriteManager spriteManager;
    FontInfo font;
    TileSurface textSurfaces[2];
    char unknown4b58[12];
    void *rowBuffers[4];
    char unknown4b74[0xc4];
    Ov005TextTable menuText;
    char unknown4c44[32];
} Ov005ResultContext;
extern Ov005ResultContext *data_ov005_0205b810;
extern void Ov005_CommitMissionResults(void);
extern void Ov005_FreeResourceRecordBuffer(Ov005TextTable *);
extern void Ov005_ReleaseThreeBuffers(Ov000ResourceTracker *);
extern void Ov005_DestroyObjectsAndRelease(Ov005SpriteManager *);
extern void FreeFieldAt8(FontInfo *),FreeAllListNodeSubBuffers(TileSurface *);
extern void ZeroHalfThenFree(void *),NNSi_FndFreeFromDefaultHeap(void *);
extern void Gfx_Reset2DEngines(void);
void Ov005_CloseResultScreen(void) {
    u8 i;
    Ov005_CommitMissionResults();
    Ov005_FreeResourceRecordBuffer(&data_ov005_0205b810->menuText);
    Ov005_ReleaseThreeBuffers(&data_ov005_0205b810->resourceTracker);
    Ov005_DestroyObjectsAndRelease(&data_ov005_0205b810->spriteManager);
    FreeFieldAt8(&data_ov005_0205b810->font);
    FreeAllListNodeSubBuffers(&data_ov005_0205b810->textSurfaces[0]);
    FreeAllListNodeSubBuffers(&data_ov005_0205b810->textSurfaces[1]);
    ZeroHalfThenFree(data_ov005_0205b810->localizedResultArchive);
    ZeroHalfThenFree(data_ov005_0205b810->resultArchive);
    for(i=0;i<4;i++) {
        if(data_ov005_0205b810->rowBuffers[i]) {
            NNSi_FndFreeFromDefaultHeap(data_ov005_0205b810->rowBuffers[i]);
            data_ov005_0205b810->rowBuffers[i]=0;
        }
    }
    Gfx_Reset2DEngines();
    data_ov005_0205b810=0;
}
