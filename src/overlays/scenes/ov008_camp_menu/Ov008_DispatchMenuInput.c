/* Ov008_DispatchMenuInput -- Ov008_DispatchMenuInput: route one frame of pressed
 * buttons to the menu's handlers, one per frame in priority order: up (0x40),
 * down (0x80), confirm (0x20), cancel (0x10), then A/B (1, 2), the two shoulder
 * buttons (0x200, 0x100) and Start (8).  The menu context getter is called for
 * its side effect only.
 */
typedef unsigned int u32;

#define KEY_A      0x0001
#define KEY_B      0x0002
#define KEY_START  0x0008
#define KEY_RIGHT  0x0010
#define KEY_LEFT   0x0020
#define KEY_UP     0x0040
#define KEY_DOWN   0x0080
#define KEY_R      0x0100
#define KEY_L      0x0200

extern void *Ov008_GetMenuContext(void);      /* Ov008_GetMenuContext */
extern void Ov008_MenuSelectionLeft(void);       /* move up */
extern void Ov008_MenuSelectionRight(void);       /* move down */
extern void Ov008_ConfirmMenuSelection(void);       /* Ov008_ConfirmMenuSelection */
extern void Ov008_CancelMenuSelection(void);       /* Ov008_CancelMenuSelection */
extern void Ov008_PageA_ConfirmAndLeave(void);       /* A / B / Start */
extern void Ov008_MenuCursorPrev(void);       /* L */
extern void Ov008_MenuCursorNext(void);       /* R */

void Ov008_DispatchMenuInput(int nUnused, u32 nKeys)
{
    Ov008_GetMenuContext();
    if ((nKeys & KEY_UP) != 0) {
        Ov008_MenuSelectionLeft();
        return;
    }
    if ((nKeys & KEY_DOWN) != 0) {
        Ov008_MenuSelectionRight();
        return;
    }
    if ((nKeys & KEY_LEFT) != 0) {
        Ov008_ConfirmMenuSelection();
        return;
    }
    if ((nKeys & KEY_RIGHT) != 0) {
        Ov008_CancelMenuSelection();
        return;
    }
    if ((nKeys & KEY_A) != 0) {
        Ov008_PageA_ConfirmAndLeave();
        return;
    }
    if ((nKeys & KEY_B) != 0) {
        Ov008_PageA_ConfirmAndLeave();
        return;
    }
    if ((nKeys & KEY_L) != 0) {
        Ov008_MenuCursorPrev();
        return;
    }
    if ((nKeys & KEY_R) != 0) {
        Ov008_MenuCursorNext();
        return;
    }
    if ((nKeys & KEY_START) != 0) {
        Ov008_PageA_ConfirmAndLeave();
    }
}
