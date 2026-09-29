/* Bind the widget's sub-node 3 to the descriptor at +0xe0, give it the caller's
 * depth (shifted into the fixed-point field) and refresh. */

#include "game/engine.h"

extern void BindAnimTrack(void *self, int slot, void *desc, int a);
extern void Anim_SetFrameWrapped(void *self, int slot, int value);

void Ov002_BindWidgetSubNode3(char *self, int depth) {
    BindAnimTrack(self, 3, self + 0xe0, 0);
    Anim_SetFrameWrapped(self, 3, depth << 0xc);
    SceneNode_Enable(self);
}
