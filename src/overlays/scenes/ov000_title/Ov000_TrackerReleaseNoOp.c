/* Empty second callback of the ov000 resource tracker config. Like every empty function it returns
 * its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov000_TrackerReleaseNoOp(void *arg)
{
    return arg;
}
