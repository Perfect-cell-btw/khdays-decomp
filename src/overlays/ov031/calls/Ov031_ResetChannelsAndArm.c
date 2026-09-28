extern void Ov031_configTwoChannelsPair();

struct S { int f0; int f4; };

void Ov031_ResetChannelsAndArm(struct S *p)
{
    Ov031_configTwoChannelsPair(p, 0, 0);
    p->f4 = 1;
}
