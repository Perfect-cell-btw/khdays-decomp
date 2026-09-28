/* Empty hook the logo/menu fade states call every frame. Like every empty function it returns its
 * first argument unchanged (the ROM is a bare `bx lr`); an object update reads that as "stay in
 * this state". */

void *Ov000_FadeStateHookNoOp(void *arg)
{
    return arg;
}
