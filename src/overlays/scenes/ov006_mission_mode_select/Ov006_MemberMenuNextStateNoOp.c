/* Empty next state of the mission member menu screen. Like every empty function it returns its
 * first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov006_MemberMenuNextStateNoOp(void *arg)
{
    return arg;
}
