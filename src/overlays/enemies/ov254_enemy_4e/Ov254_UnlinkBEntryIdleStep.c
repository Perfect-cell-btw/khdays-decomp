/* Empty step Ov254_UnlinkBEntry installs: the actor does nothing until something else replaces it.
 * Like every empty function it returns its first argument unchanged (the ROM is a bare `bx lr`); an
 * object update reads that as "stay in this state". */

void *Ov254_UnlinkBEntryIdleStep(void *arg)
{
    return arg;
}
