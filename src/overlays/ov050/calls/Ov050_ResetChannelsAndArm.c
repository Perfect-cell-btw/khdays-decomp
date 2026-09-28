extern void Ov050_configTwoChannelsPair();

struct S { int f0; int f4; };

void Ov050_ResetChannelsAndArm(struct S *p)
{
    Ov050_configTwoChannelsPair(p, 0, 0);
    p->f4 = 1;
}
