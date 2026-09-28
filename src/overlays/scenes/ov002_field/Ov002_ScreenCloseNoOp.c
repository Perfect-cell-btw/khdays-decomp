/* Empty close handler of screen descriptor data_ov002_0207e720. Like every empty function it
 * returns its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as
 * "stay in this state". */

void *Ov002_ScreenCloseNoOp(void *arg)
{
    return arg;
}
