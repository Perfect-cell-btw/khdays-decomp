/* Reward menu tick: updates key repeat and the widgets, runs the current state, draws the frame and
 * uploads the dirty text. */

#include "game/engine.h"

typedef void (*Ov005MenuStateHandler)(void);
typedef struct Ov005MenuStateTable { Ov005MenuStateHandler states[9]; } Ov005MenuStateTable;
typedef struct Ov000ResourceTracker { char opaque[76]; } Ov000ResourceTracker;
typedef struct Ov005SpriteManager { char opaque[0x4a80]; } Ov005SpriteManager;
typedef struct MenuLimitHeader { char opaque[26]; } MenuLimitHeader;
typedef struct Ov005Context {
    char header[8];
    Ov000ResourceTracker resourceTracker;
    Ov005SpriteManager embeddedManager;
    char opaque4ad4[0x11c];
    int menuState;
    char opaque4bf4[0x1e];
    MenuLimitHeader menuLimitHeader;
} Ov005Context;
extern const Ov005MenuStateTable data_ov005_0205b368;
extern Ov005Context *data_ov005_0205b80c;
extern void Ov005_TickSelectionWidget(Ov000ResourceTracker *);
extern void Ov005_UpdateWidgetLayerDefault(Ov005SpriteManager *,int);
extern void Ov005_DrawMenuFrame(void);
extern void Ov005_EnqueueDirtyTextBuffers(void);
void *Ov005_UpdateMainScene(void) {
    Ov005MenuStateTable handlers=data_ov005_0205b368;
    func_020362ec(&data_ov005_0205b80c->menuLimitHeader);
    Ov005_TickSelectionWidget(&data_ov005_0205b80c->resourceTracker);
    Ov005_UpdateWidgetLayerDefault(&data_ov005_0205b80c->embeddedManager,0);
    handlers.states[data_ov005_0205b80c->menuState]();
    if(data_ov005_0205b80c->menuState>1)Ov005_DrawMenuFrame();
    Ov005_EnqueueDirtyTextBuffers();
    return 0;
}
