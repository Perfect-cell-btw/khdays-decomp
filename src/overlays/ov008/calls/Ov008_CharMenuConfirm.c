/* Ov008_CharMenuConfirm -- ov008 character menu confirm. If the roster cursor (GameState_GetField slot 9)
 * is below 8 it is an empty slot: just fire UI event 4. Otherwise commit the pick
 * (Ov008_SelectMenuGroupAndDrawCaption(obj, 2)) and fire UI event 1. */
extern int  Ov008_GetMenuContext(void);
extern unsigned int GameState_GetField(int a, int b);
extern void PlaySound(int a, int b);
extern void Ov008_SelectMenuGroupAndDrawCaption(int obj, int arg);

void Ov008_CharMenuConfirm(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4) {
    int obj = Ov008_GetMenuContext();
    unsigned int slot = GameState_GetField(0, 9);
    if (slot <= 7) {
        PlaySound(0, 4);
        return;
    }
    Ov008_SelectMenuGroupAndDrawCaption(obj, 2);
    PlaySound(0, 1);
}
