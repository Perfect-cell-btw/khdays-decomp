/* Sets state 3 with the value and clears the counter. */

struct S {
    int f0;
    int f4;
};

void Ov031_ArmState3(int *p, int v)
{
    p[1] = 3;
    p[0x44] = v;
    p[0x45] = 0;
}
