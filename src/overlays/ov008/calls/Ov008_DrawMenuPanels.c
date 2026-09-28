/* Ov008_DrawMenuPanels -- Ov008_DrawMenuPanels (136 B, 9 relocs).
 * Redraws the menu's cell panels. After two refresh hooks (Ov008_MenuCursor_TweenStep /
 * Ov008_UpdatePanelBrightnessTweens), it walks the 12 panel surfaces (stride 0x108 starting at ctx+0x590),
 * and for each whose gate entry data_ov008_0208f050[i] is non-negative it binds the surface to
 * the shared resource (*ctx) via Sequence_UpdateTracks and enqueues it via Scene_DrawNode. Finally it
 * binds+enqueues the two fixed surfaces at ctx+0x488 and ctx+0x380 unconditionally. */
extern int  data_ov008_0208f050[];
extern void Ov008_MenuCursor_TweenStep(void *ctx);
extern void Ov008_UpdatePanelBrightnessTweens(void *ctx);
extern void Sequence_UpdateTracks(void *dst, int val);
extern void Scene_DrawNode(void *dst);

void Ov008_DrawMenuPanels(void *ctx)
{
    int i;
    char *slot;

    Ov008_MenuCursor_TweenStep(ctx);
    Ov008_UpdatePanelBrightnessTweens(ctx);
    slot = (char *)ctx + 0x590;
    for (i = 0; i < 0xc; i++) {
        if (data_ov008_0208f050[i] >= 0) {
            Sequence_UpdateTracks(slot, *(int *)ctx);
            Scene_DrawNode(slot);
        }
        slot += 0x108;
    }
    Sequence_UpdateTracks((char *)ctx + 0x488, *(int *)ctx);
    Scene_DrawNode((char *)ctx + 0x488);
    Sequence_UpdateTracks((char *)ctx + 0x380, *(int *)ctx);
    Scene_DrawNode((char *)ctx + 0x380);
}
