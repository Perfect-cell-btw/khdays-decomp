/* Empty slot 1 of a collider function table (data_02042940). Like every empty function it returns
 * its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Collider_Slot1NoOp_2(void *arg)
{
    return arg;
}
