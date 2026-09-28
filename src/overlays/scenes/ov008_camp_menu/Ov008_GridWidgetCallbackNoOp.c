/* Empty callback for grid menu widget 0x35. Like every empty function it returns its first argument
 * unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this state". */

void *Ov008_GridWidgetCallbackNoOp(void *arg)
{
    return arg;
}
