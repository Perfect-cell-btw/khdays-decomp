/* Empty callback for grid menu widget 0x36. Like every empty function it returns its first argument
 * unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this state". */

void *Ov025_GridWidgetCallbackNoOp_2(void *arg)
{
    return arg;
}
