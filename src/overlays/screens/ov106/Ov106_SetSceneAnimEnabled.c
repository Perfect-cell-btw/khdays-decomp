/* Enable or disable the ov106 scene's +0x8bc4 animation: track 4 is set to 1.0 or 0 and the node
 * re-evaluates (0202af1c). No-op without a scene. */
extern char *data_ov106_020b8b60;
extern void Anim_SetFrameWrapped(void *node, int track, int frame);
extern void SceneNode_Enable(void *node);

void Ov106_SetSceneAnimEnabled(int enable)
{
    if (data_ov106_020b8b60 == 0) {
        return;
    }
    Anim_SetFrameWrapped(data_ov106_020b8b60 + 0x8bc4, 4, enable != 0 ? 0x1000 : 0);
    SceneNode_Enable(data_ov106_020b8b60 + 0x8bc4);
}
