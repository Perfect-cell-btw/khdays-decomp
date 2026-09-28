/* Empty entry of the mode-select state table (data_ov000_0205a86c). Like every empty function it
 * returns its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as
 * "stay in this state". */

void *Ov000_ModeSelectStateNoOp(void *arg)
{
    return arg;
}
