/* Moves the page index one step (wrapping over eight pages) until the menu accepts the page. */

extern int Ov008_Menu_ChangePage(void *context, int index);

void Ov008_AdvanceIndexBackwardUntilOk(void *context, int index)
{
    do {
        index = (index + 7) % 8;
    } while (Ov008_Menu_ChangePage(context, index) == 0);
}
