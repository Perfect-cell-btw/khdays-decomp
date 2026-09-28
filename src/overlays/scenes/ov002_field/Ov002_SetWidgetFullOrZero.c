/* Set sub-node 4 of the context's widget at +0x610 to the full Q12 value when
 * enabling and to zero when disabling, then refresh it. Does nothing with no
 * context installed. */
extern void Anim_SetFrameWrapped(void *node, int slot, int value);
extern void SceneNode_Enable(void *node);

extern char *data_ov002_0207f628;

void Ov002_SetWidgetFullOrZero(int enable) {
    char *ctx = data_ov002_0207f628;

    if (ctx == 0) {
        return;
    }

    Anim_SetFrameWrapped(ctx + 0x610, 4, enable != 0 ? 0x1000 : 0);
    SceneNode_Enable(ctx + 0x610);
}
