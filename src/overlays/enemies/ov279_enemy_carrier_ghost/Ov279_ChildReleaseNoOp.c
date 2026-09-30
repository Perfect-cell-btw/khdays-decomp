/* Empty second callback of the task entry Ov279_SpawnChildStoreSelfAndArg creates. Like every empty
 * function it returns its first argument unchanged (the ROM is a bare `bx lr`); an object update
 * reads that as "stay in this state". */

void *Ov279_ChildReleaseNoOp(void *arg)
{
    return arg;
}
