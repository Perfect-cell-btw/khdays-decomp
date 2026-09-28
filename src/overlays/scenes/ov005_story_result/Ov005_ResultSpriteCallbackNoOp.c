/* Empty callback registered for result sprite 18. Like every empty function it returns its first
 * argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this
 * state". */

void *Ov005_ResultSpriteCallbackNoOp(void *arg)
{
    return arg;
}
