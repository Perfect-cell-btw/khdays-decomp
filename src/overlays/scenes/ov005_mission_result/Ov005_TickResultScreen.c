/* Tick result resources, dispatch the active phase, and flush pending buffers. */

#include "game/engine.h"

typedef void (*Ov005ResultPhaseHandler)(void);
typedef struct Ov005ResultPhaseTable { Ov005ResultPhaseHandler states[5]; } Ov005ResultPhaseTable;
typedef struct Ov000ResourceTracker { char opaque[76]; } Ov000ResourceTracker;
typedef struct Ov005SpriteManager { char opaque[0x4a80]; } Ov005SpriteManager;
typedef struct Ov005ResultContext {
    char unknown00[8];
    Ov000ResourceTracker resourceTracker;
    Ov005SpriteManager spriteManager;
    char unknown4ad4[0xa0];
    int resultPhase;
} Ov005ResultContext;
extern Ov005ResultContext *data_ov005_0205b810;
extern const Ov005ResultPhaseTable data_ov005_0205b39c;
extern unsigned short Ov105_WM_GetLinkLevel(void);
extern void Ov005_SelectAndShowResultSprite(int, unsigned int);
extern void Ov005_TickSelectionWidget(Ov000ResourceTracker *);
extern void Ov005_UpdateWidgetLayerDefault(Ov005SpriteManager *, int);
extern void Ov005_FlushDirtyResultRows(void);
void *Ov005_TickResultScreen(void) {
    Ov005ResultPhaseTable handlers = data_ov005_0205b39c;
    if (Session_IsActive()) Ov005_SelectAndShowResultSprite(108, (unsigned char)Ov105_WM_GetLinkLevel());
    Ov005_TickSelectionWidget(&data_ov005_0205b810->resourceTracker);
    Ov005_UpdateWidgetLayerDefault(&data_ov005_0205b810->spriteManager, 0);
    handlers.states[data_ov005_0205b810->resultPhase]();
    Ov005_FlushDirtyResultRows();
    return 0;
}
