/* Ov008_FeedScrollInput -- feed input param_1 to the ov008 menu's scroll widget when it is idle.
 * Gets the menu object; bails if a page transition is running (Ov008_GetCtxObject9634) or the widget
 * is disabled (Ov008_GetCtxObject9630 == 0); otherwise forwards to Ov008_RebuildQueryList (obj+0x13fc)
 * and refreshes (Ov008_SortListByKey). */
extern int  Ov008_GetMenuContext(void);
extern int  Ov008_GetCtxObject9634(void);
extern int  Ov008_GetCtxObject9630(void);
extern void Ov008_RebuildQueryList(int widget, unsigned int input);
extern void Ov008_SortListByKey(int obj);

void Ov008_FeedScrollInput(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4) {
    int obj = Ov008_GetMenuContext();
    if (Ov008_GetCtxObject9634() != 0) {
        return;
    }
    if (Ov008_GetCtxObject9630() == 0) {
        return;
    }
    Ov008_RebuildQueryList(obj + 0x13fc, param_1);
    Ov008_SortListByKey(obj);
}
