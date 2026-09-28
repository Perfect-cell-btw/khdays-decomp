/* Ov008_PanelRefresh -- per-frame refresh of the ov008 panel widget.
 * Ticks the widget (ctx+0xbfb8); unless the panel is in mode 2 with a live handle (ctx+0xc250 == 2
 * && ctx+0xc51c != 0), resets its stream (ctx+0xbff0); then advances it by 0x1000. */
extern void Camera_CommitMatrices(void *node);
extern void Scene_DrawNode(unsigned short *p);
extern void Sequence_UpdateTracks(unsigned short *p, int step);
extern int  data_ov008_02090fac;   /* -> panel context */

void Ov008_PanelRefresh(void) {
    int ctx = data_ov008_02090fac;
    int w = ctx + 0xbfb8;
    Camera_CommitMatrices((void *)w);
    if (*(int *)(ctx + 0xc250) != 2 || *(int *)(ctx + 0xc51c) == 0) {
        Scene_DrawNode((unsigned short *)(w + 0x38));
    }
    Sequence_UpdateTracks((unsigned short *)(w + 0x38), 0x1000);
}
