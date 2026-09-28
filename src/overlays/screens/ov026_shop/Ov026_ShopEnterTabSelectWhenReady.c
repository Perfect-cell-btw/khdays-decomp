/* Shop state: refreshes touch and panel; moves to the tab-select tick once ready. */

extern int Ov026_FadeInStep(void);
extern void Ov026_UpdateTouchState(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_ShopTabSelectTick(void);

void (*Ov026_ShopEnterTabSelectWhenReady(void))(void)
{
    void (*callback)(void);

    if (Ov026_FadeInStep() != 0) {
        callback = Ov026_ShopTabSelectTick;
    } else {
        callback = 0;
    }

    Ov026_UpdateTouchState();
    Ov026_RefreshPanelDisplay();

    return callback;
}
