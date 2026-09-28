extern void EnqueueObjGfxCommand(char *p);
extern void Ov002_SelectEntry(int id);
extern int Ov002_GetPanelField0058(void);
extern void Ov002_DrawNoticeGauge(void);
extern char *data_ov002_0207f62c;

/* Per-frame tick of the options page: closes the open sub-window if there is one, then hands the
 * frame to the page body while the page is still active. */
void Ov002_TickOptionsPage(void) {
    char *page = (&data_ov002_0207f62c)[1];
    if (*(int *)(page + 0x90) != 0) {
        EnqueueObjGfxCommand(page + 0xfc);
        Ov002_SelectEntry(0x1a);
    }
    if (Ov002_GetPanelField0058() == 0) {
        return;
    }
    Ov002_DrawNoticeGauge();
}
