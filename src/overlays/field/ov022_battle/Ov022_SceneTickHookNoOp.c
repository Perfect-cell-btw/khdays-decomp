/* Empty hook the scene tick dispatch calls with heap+0x68. Like every empty function it returns its
 * first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov022_SceneTickHookNoOp(void *arg)
{
    return arg;
}
