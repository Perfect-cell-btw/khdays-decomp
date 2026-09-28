/* Configures both channels to 0 and marks the object armed. */

extern void Ov088_configTwoChannelsPair();

struct S { int f0; int f4; };

void Ov088_ResetChannelsAndArm(struct S *p)
{
    Ov088_configTwoChannelsPair(p, 0, 0);
    p->f4 = 1;
}
