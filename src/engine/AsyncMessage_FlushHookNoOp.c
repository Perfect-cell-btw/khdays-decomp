/* Empty hook called twice from AsyncMessage_Flush. Like every empty function it returns its first
 * argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this
 * state". */

void *AsyncMessage_FlushHookNoOp(void *arg)
{
    return arg;
}
