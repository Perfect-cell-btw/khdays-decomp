/* Loads the selected opening sprite character resource into BG0, BG1 or BG2, sets sub-screen
 * brightness to -16, and advances the opening timeline. */

#include "nitro/types.h"

typedef struct Ov012OpeningEvent {
    u32 nTriggerThreadDelta;
    u16 uHandlerIndex;
    u16 uSpriteResourceIndex;
    u16 uBackgroundLayer;
    u16 uAuxValue;
} Ov012OpeningEvent;

typedef struct Ov002PageChars {
    u8 reserved00[0x10];
    u32 nCharSize;
    void *pCharData;
} Ov002PageChars;

extern void GX_LoadBG0Char(void *pSource, u32 destinationOffset, u32 size);
extern void GX_LoadBG1Char(void *pSource, u32 destinationOffset, u32 size);
extern void GX_LoadBG2Char(void *pSource, u32 destinationOffset, u32 size);

int Ov012_LoadOpeningBgCharacters(void *pContext, u32 nThreadDelta,
                             Ov012OpeningEvent *pEvent) {
    char *context;
    Ov002PageChars *pCharacterResource;

    context = (char *)pContext;
    pCharacterResource = *(Ov002PageChars **)(
        context + pEvent->uSpriteResourceIndex * 0xc + 0x8c04);

    if (pEvent->uBackgroundLayer == 0) goto bg0;
    if (pEvent->uBackgroundLayer == 1) goto bg1;
    if (pEvent->uBackgroundLayer != 2) goto done;
    goto bg2;

bg0:
    GX_LoadBG0Char(pCharacterResource->pCharData, 0,
                   pCharacterResource->nCharSize);
    goto done;

bg1:
    GX_LoadBG1Char(pCharacterResource->pCharData, 0,
                   pCharacterResource->nCharSize);
    goto done;

bg2:
    GX_LoadBG2Char(pCharacterResource->pCharData, 0,
                   pCharacterResource->nCharSize);

done:

    *(int *)(context + 0x8bf4) = -16;
    return 1;
}
