/* Closes the reward menu: commits the rewards and frees its buffers, text, sprites, fonts, surfaces
 * and archives. */

typedef struct Ov000ResourceTracker { char opaque[76]; } Ov000ResourceTracker;
typedef struct Ov005SpriteManager { char opaque[0x4a80]; } Ov005SpriteManager;
typedef struct FontInfo { char opaque[12]; } FontInfo;
typedef struct TileSurface { char opaque[60]; } TileSurface;
typedef struct MenuLimitHeader { char opaque[26]; } MenuLimitHeader;
typedef struct TextTable { char opaque[12]; } TextTable;
typedef struct Ov005DescriptionCache { char opaque[16]; } Ov005DescriptionCache;
typedef struct Ov005Context {
    void *resultArchive,*localizedResultArchive;
    Ov000ResourceTracker resourceTracker;
    Ov005SpriteManager embeddedManager;
    Ov005SpriteManager *spriteManager;
    FontInfo fonts[2];
    TileSurface textSurfaces[4];
    int activeBufferIndex;
    void *rowBuffers[3];
    char opaque4bf0[0x22];
    MenuLimitHeader menuLimitHeader;
    char opaque4c2c[0x5d550];
    TextTable menuText;
    Ov005DescriptionCache descriptionCache;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void Ov005_CommitMenuRewards(void);
extern void NNSi_FndFreeFromDefaultHeap(void *);
extern void ConstReturn1_2(MenuLimitHeader *);
extern void Ov005_FreeResourceRecordBuffer(TextTable *);
extern void Ov005_ReleaseThreeBuffers(Ov000ResourceTracker *);
extern void Ov005_DestroyObjectsAndRelease(Ov005SpriteManager *);
extern void FreeFieldAt8(FontInfo *);
extern void Ov005_InvokeMethod8(Ov005DescriptionCache *);
extern void FreeAllListNodeSubBuffers(TileSurface *);
extern void ZeroHalfThenFree(void *);
void Ov005_CloseMainMenu(void) {
    unsigned char i;
    Ov005_CommitMenuRewards();
    for(i=0;i<3;i++)NNSi_FndFreeFromDefaultHeap(data_ov005_0205b80c->rowBuffers[i]);
    ConstReturn1_2(&data_ov005_0205b80c->menuLimitHeader);
    Ov005_FreeResourceRecordBuffer(&data_ov005_0205b80c->menuText);
    Ov005_ReleaseThreeBuffers(&data_ov005_0205b80c->resourceTracker);
    Ov005_DestroyObjectsAndRelease(&data_ov005_0205b80c->embeddedManager);
    FreeFieldAt8(&data_ov005_0205b80c->fonts[1]);
    FreeFieldAt8(&data_ov005_0205b80c->fonts[0]);
    Ov005_InvokeMethod8(&data_ov005_0205b80c->descriptionCache);
    for(i=0;i<4;i++)FreeAllListNodeSubBuffers(&data_ov005_0205b80c->textSurfaces[i]);
    ZeroHalfThenFree(data_ov005_0205b80c->localizedResultArchive);
    ZeroHalfThenFree(data_ov005_0205b80c->resultArchive);
    data_ov005_0205b80c=0;
}
