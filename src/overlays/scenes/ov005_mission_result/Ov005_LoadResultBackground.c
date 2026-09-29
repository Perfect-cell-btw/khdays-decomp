/* Loads the result background's palette and character data for both layers. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct PaletteData {char pad0[8];u32 size;void *data;} PaletteData;
typedef struct CharacterData {char pad0[16];u32 size;void *data;} CharacterData;
typedef struct SpriteResSet {void *screen;CharacterData *character;PaletteData *palette;} SpriteResSet;
typedef struct Ov005Context {u32 resultArchive;} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void *Archive_LoadFile(u32,int);
extern void GX_LoadBGPltt(void *,u32,u32);
extern void GX_LoadBG3Char(void *,u32,u32);
extern void GX_LoadBG1Char(void *,u32,u32);
extern void NNSi_FndFreeFromDefaultHeap(void *);
void Ov005_LoadResultBackground(void) {
    SpriteResSet resources;
    void *archive;
    archive=Archive_LoadFile((((data_ov005_0205b80c->resultArchive+0x8000)&0xfffffc)<<7)|0x80000000,14);
    Res_LoadSpriteSet(&resources,archive,-1,2,0);
    GX_LoadBGPltt(resources.palette->data,0,resources.palette->size);
    GX_LoadBG3Char(resources.character->data,0,resources.character->size);
    Res_LoadSpriteSet(&resources,archive,-1,4,-1);
    GX_LoadBG1Char(resources.character->data,0,resources.character->size);
    if(archive)NNSi_FndFreeFromDefaultHeap(archive);
}
