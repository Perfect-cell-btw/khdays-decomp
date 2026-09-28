/* Empty entry 12 of the 15-entry mission step table. Like every empty function it returns its first
 * argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in this
 * state". */

void *Ov006_MissionStep12NoOp(void *arg)
{
    return arg;
}
