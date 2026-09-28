/* Empty last entry of the title state table. Like every empty function it returns its first
 * argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this
 * state". */

void *Ov011_TitleStateNoOp(void *arg)
{
    return arg;
}
