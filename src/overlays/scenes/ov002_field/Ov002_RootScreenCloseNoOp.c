/* Empty close handler of the root screen descriptor (open = CaptureRootHeap). Like every empty
 * function it returns its first argument unchanged (the ROM is a bare `bx lr`); an object update
 * reads that as "stay in this state". */

void *Ov002_RootScreenCloseNoOp(void *arg)
{
    return arg;
}
