/*
 * Ov008_Menu_RenderScenePanels - per-frame render and gfx submit of the menu scene's
 * two panel widgets, called from Ov008_Menu_AdvanceIntoPanel.
 *
 * Updates the scene sprite node (obj+0x38) with the current scroll base (obj+0x1b0) and
 * renders it, then for each active panel slot submits its widget:
 *   - slot 1 (valid flag obj+0x140): panel obj+0x1b8, matrix obj+0x150;
 *   - slot 2 (valid flag obj+0x144): panel obj+0x31c, matrix obj+0x180.
 * For each active panel it reads the node's current anim frame, commits the widget scroll
 * (obj+0x480 output), scales the panel matrix to 100.0 (0x64000 in fx32) when the scene is
 * in state 0xd, applies the matrix to the panel object and submits its gfx.
 *
 * Callee arity (Ghidra invents trailing r2/r3 args from the scale block): Scene_DrawNode
 * (RenderNode) takes 1 arg, Ov008_SubmitObjectGfx (SubmitObjectGfx) takes 1 arg. The two
 * scale constants Ghidra threads into SubmitObjectGfx are only live on the state-0xd path.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void Sequence_UpdateTracks(u16 *node, int scrollBase);
extern void Scene_DrawNode(u16 *node);
extern int  Anim_GetFrame(u16 *node, int a);
extern void Ov008_WidgetScrollCommit(int panel, int out, int scrollBase, int frame);
extern void MTX_ScaleApply43(int *dst, u32 *src, int sx, int sy, int sz);
extern void Ov008_SetMatrix43(void *panel, void *mtx);
extern void Ov008_SubmitObjectGfx(u8 *panel);

void Ov008_Menu_RenderScenePanels(int obj)
{
    int frame;
    int scrollBase;

    Sequence_UpdateTracks((u16 *)(obj + 0x38), *(int *)(obj + 0x1b0));
    Scene_DrawNode((u16 *)(obj + 0x38));
    if (*(int *)(obj + 0x140) != 0) {
        frame = Anim_GetFrame((u16 *)(obj + 0x38), 0);
        scrollBase = *(int *)(obj + 0x1b0);
        Ov008_WidgetScrollCommit(obj + 0x1b8, obj + 0x480, scrollBase, frame);
        if (*(int *)(obj + 0x524) == 0xd) {
            MTX_ScaleApply43((int *)(obj + 0x150), (u32 *)(obj + 0x150), 0x64000, 0x64000, 0x64000);
        }
        Ov008_SetMatrix43((void *)(obj + 0x1b8), (void *)(obj + 0x150));
        Ov008_SubmitObjectGfx((u8 *)(obj + 0x1b8));
    }
    if (*(int *)(obj + 0x144) != 0) {
        frame = Anim_GetFrame((u16 *)(obj + 0x38), 0);
        scrollBase = *(int *)(obj + 0x1b0);
        Ov008_WidgetScrollCommit(obj + 0x31c, obj + 0x480, scrollBase, frame);
        if (*(int *)(obj + 0x524) == 0xd) {
            MTX_ScaleApply43((int *)(obj + 0x180), (u32 *)(obj + 0x180), 0x64000, 0x64000, 0x64000);
        }
        Ov008_SetMatrix43((void *)(obj + 0x31c), (void *)(obj + 0x180));
        Ov008_SubmitObjectGfx((u8 *)(obj + 0x31c));
    }
}
