/* Empty callback for hub widget 0x66. Like every empty function it returns its first argument
 * unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this state". */

void *Ov025_HubWidgetCallbackNoOp_2(void *arg)
{
    return arg;
}
