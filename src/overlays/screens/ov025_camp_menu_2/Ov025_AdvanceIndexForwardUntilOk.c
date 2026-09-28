/* Moves the page index one step (wrapping over eight pages) until the menu accepts the page. */

extern int Ov025_Menu_ChangePage();

void Ov025_AdvanceIndexForwardUntilOk(int arg0, int arg1) {
    do {
        arg1 = (arg1 + 1) % 8;
    } while (Ov025_Menu_ChangePage(arg0, arg1) == 0);
}
