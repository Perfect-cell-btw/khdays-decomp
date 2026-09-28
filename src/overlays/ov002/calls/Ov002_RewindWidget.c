/*
 * Ov002_RewindWidget - put a widget back to the start of its animation.
 *
 * Both of its animated slots are re-bound to the sub-node and driven back to
 * zero, then the widget is refreshed - held on the first frame when the caller
 * asks for it, free-running otherwise.
 *
 * ARM.
 */

extern void BindAnimTrack(void *pWidget, int nSlot, void *pNode, int nFlags);
extern void Anim_SetFrameWrapped(void *pWidget, int nSlot, int nValue);
extern void SceneNode_Enable(void *pWidget);
extern void SceneNode_Disable(void *pWidget);

void Ov002_RewindWidget(void *pWidget, int bHold)
{
    BindAnimTrack(pWidget, 0, (char *)pWidget + 0xe0, 0);
    BindAnimTrack(pWidget, 2, (char *)pWidget + 0xe0, 0);
    Anim_SetFrameWrapped(pWidget, 0, 0);
    Anim_SetFrameWrapped(pWidget, 2, 0);
    if (bHold != 0) {
        SceneNode_Disable(pWidget);
    } else {
        SceneNode_Enable(pWidget);
    }
}
