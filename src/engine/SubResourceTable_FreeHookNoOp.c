/* Empty hook: does nothing. Like every empty function it returns its first argument unchanged (the
 * ROM is a bare `bx lr`); an object update reads that as "stay in this state". */

void *SubResourceTable_FreeHookNoOp(void *arg)
{
    return arg;
}
