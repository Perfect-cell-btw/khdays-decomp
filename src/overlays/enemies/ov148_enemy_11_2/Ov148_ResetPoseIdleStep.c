/* Empty step Ov148_ResetPoseAndFlags installs: the actor does nothing until something else replaces
 * it. Like every empty function it returns its first argument unchanged (the ROM is a bare `bx
 * lr`); an object update reads that as "stay in this state". */

void *Ov148_ResetPoseIdleStep(void *arg)
{
    return arg;
}
