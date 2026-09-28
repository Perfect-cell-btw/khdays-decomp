/* Empty hook Ov025_BuildMenuScreen calls with (ctx, 0). Like every empty function it returns its
 * first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov025_BuildMenuHookNoOp(void *arg)
{
    return arg;
}
