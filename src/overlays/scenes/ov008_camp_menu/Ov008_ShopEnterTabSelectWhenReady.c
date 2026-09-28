/* Shop state: refreshes touch and panel; moves to the tab-select tick once ready. */

extern int Ov008_FadeInStep(void);
extern void Ov008_UpdateTouchState(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_ShopTabSelectTick(void);

void (*Ov008_ShopEnterTabSelectWhenReady(void))(void)
{
    void (*callback)(void);

    if (Ov008_FadeInStep() != 0) {
        callback = Ov008_ShopTabSelectTick;
    } else {
        callback = 0;
    }

    Ov008_UpdateTouchState();
    Ov008_RefreshPanelDisplay();

    return callback;
}
