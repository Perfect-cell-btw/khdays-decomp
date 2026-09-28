/* Accept the request and, when there is a live context and the transition has
 * finished, notify with 3 for a non-zero request and -1 for a zero one. Reports
 * whether the request was accepted at all. */
extern int Ov002_Panel_GetCursor(int req);
extern int Ov002_GetPanelField018c(void);
extern void Ov002_HudReset(int code);

extern char *data_ov002_0207f614;

int Ov002_AcceptRequestAndNotify(int req) {
    if (Ov002_Panel_GetCursor(req) == 0) {
        return 0;
    }

    if (data_ov002_0207f614 != 0 && Ov002_GetPanelField018c() != 0) {
        Ov002_HudReset(req != 0 ? 3 : -1);
    }

    return 1;
}
