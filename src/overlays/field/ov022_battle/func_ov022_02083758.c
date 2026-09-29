/* Pushes the VRAM state, runs the frame without input and moves to ending the scene for each
 * player. */

#include "game/engine.h"

extern void Ov022_UpdateCameraAndViews(int arg0);
extern int Ov022_EndSceneForEachPlayer(void);
int func_ov022_02083758(void) {
    EntityMgr_PushVramState();
    Ov022_UpdateCameraAndViews(0);
    return (int)&Ov022_EndSceneForEachPlayer;
}
