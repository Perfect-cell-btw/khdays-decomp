/* Empty hook called when a page is committed and submitted. Like every empty function it returns
 * its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov002_PageSubmitHookNoOp(void *arg)
{
    return arg;
}
