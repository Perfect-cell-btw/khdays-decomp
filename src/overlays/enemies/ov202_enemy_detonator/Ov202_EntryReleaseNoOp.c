/* Empty second callback of the task entry Ov202_CreateRegistryEntryTwoCallbacks creates. Like every
 * empty function it returns its first argument unchanged (the ROM is a bare `bx lr`); an object
 * update reads that as "stay in this state". */

void *Ov202_EntryReleaseNoOp(void *arg)
{
    return arg;
}
