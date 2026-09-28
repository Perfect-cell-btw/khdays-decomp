/* Empty callback registered for result sprite 21. Like every empty function it returns its first
 * argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this
 * state". */

void *Ov005_ResultSpriteCallbackNoOp_4(void *arg)
{
    return arg;
}
