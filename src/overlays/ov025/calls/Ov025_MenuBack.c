/* Ov025_MenuBack -- ov025 "back": close the sub-panel (obj+0x94) if one is open, else the
 * popup (obj+0x5c0) if one is open, else leave the menu entirely (Ov002_PostResultReport + clear the
 * selection). Always fires UI event 3. */
extern void Ov025_Hub_SelectMenuGroup(int obj, int arg);
extern void Ov025_Hub_SetSubMenu(int obj, int arg);
extern void Ov002_PostResultReport(int arg);
extern void Ov025_SetTargetSlot(int a, int b);
extern void PlaySound(int a, int b);

void Ov025_MenuBack(int param_1) {
    if (*(int *)(param_1 + 0x94) != 0) {
        Ov025_Hub_SelectMenuGroup(param_1, 0);
    } else if (*(int *)(param_1 + 0x5c0) != 0) {
        Ov025_Hub_SetSubMenu(param_1, 0);
    } else {
        Ov002_PostResultReport(0);
        Ov025_SetTargetSlot(-1, -1);
    }
    PlaySound(0, 3);
}
