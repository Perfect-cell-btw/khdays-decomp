/* Turns the resource's +0x14 offset into an absolute pointer. */

void Res_RelocateField14B(int *p)
{
    p[5] += (int)p;
}
