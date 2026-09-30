/* Empty step Ov254_TwinMarker_AiEnterIdle installs: the actor does nothing until something else
 * replaces it. Like every empty function it returns its first argument unchanged (the ROM is a bare
 * `bx lr`); an object update reads that as "stay in this state". */

void *Ov254_TwinMarker_IdleStep(void *arg)
{
    return arg;
}
