/* Ov107_Region_OnBusy -- request node action bit 1 when idle, ov107. Forwards to
 * Ov107_Region_DrawStatusFx(node, 1) only if the busy flag (arg1) is clear. */
extern void Ov107_Region_DrawStatusFx(void *node, int action);
void Ov107_Region_OnBusy(void *node, int busy) {
    if (busy == 0) {
        Ov107_Region_DrawStatusFx(node, 1);
    }
}
