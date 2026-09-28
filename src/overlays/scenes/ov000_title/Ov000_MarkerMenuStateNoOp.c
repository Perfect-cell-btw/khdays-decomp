/* Empty last entry of the marker-menu state table (data_ov000_0205a710). Like every empty function
 * it returns its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that
 * as "stay in this state". */

void *Ov000_MarkerMenuStateNoOp(void *arg)
{
    return arg;
}
