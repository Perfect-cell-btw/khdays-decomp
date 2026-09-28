/* Empty hook the mission confirm/selection screens call. Like every empty function it returns its
 * first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov008_MissionMenuHookNoOp(void *arg)
{
    return arg;
}
