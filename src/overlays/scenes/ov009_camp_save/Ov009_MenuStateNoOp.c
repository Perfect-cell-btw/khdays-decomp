/* Empty entry used for the unused states of the ov009 menu handler table. Like every empty function
 * it returns its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that
 * as "stay in this state". */

void *Ov009_MenuStateNoOp(void *arg)
{
    return arg;
}
