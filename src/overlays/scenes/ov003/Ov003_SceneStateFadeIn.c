/* Fades both screens out over 16 frames and then finishes the scene. */

#include "game/engine.h"

#include "game/scene.h"
typedef struct {
    unsigned char pad0000[0x1774];
    int nFadeTicks;
    unsigned char pad1778[0x698];
    int nInitGuard;
    int nInitValue;
} Ov003RootContext;

extern Ov003RootContext *NNSi_FndGetCurrentRootHeap(void);
extern int Ov105_WM_GetLinkLevel(void);
extern void Ov003_UpdateLayers(int a);
extern void Ov003_AdvanceAnims(int a);

int Ov003_SceneStateFadeIn(void) {
    Ov003RootContext *root = NNSi_FndGetCurrentRootHeap();

    if (root->nInitGuard == 0) {
        root->nInitValue = Ov105_WM_GetLinkLevel();
    }
    Ov003_UpdateLayers((int)root);

    if (root->nFadeTicks < 0x10) {
        int n = root->nFadeTicks + 1;

        root->nFadeTicks = n;
        SetMasterBrightnessMain(-n);
        SetMasterBrightnessSub(-root->nFadeTicks);
    } else {
        Scene_RequestPending(SCENE_MISSION_RESULT, 0);
        return -2;
    }
    Ov003_AdvanceAnims((int)root);
    return 0;
}
