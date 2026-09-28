/* Empty slot 0 of the ov024 stack-allocator function table. Like every empty function it returns
 * its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov024_StackAllocVtblSlot0NoOp(void *arg)
{
    return arg;
}
