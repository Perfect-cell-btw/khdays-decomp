/* Empty callback for widget 9 of the menu entry layout. Like every empty function it returns its
 * first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov008_MenuEntryWidgetCallbackNoOp(void *arg)
{
    return arg;
}
