/* Empty hook: does nothing. Like every empty function it returns its first argument unchanged (the
 * ROM is a bare `bx lr`); an object update reads that as "stay in this state". */

void *Ov146_AiSlot1NoOp(void *arg)
{
    return arg;
}
