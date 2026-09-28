extern void Ov070_configTwoChannelsPair();

struct S { int f0; int f4; };

void Ov070_ResetChannelsAndArm(struct S *p)
{
    Ov070_configTwoChannelsPair(p, 0, 0);
    p->f4 = 1;
}
