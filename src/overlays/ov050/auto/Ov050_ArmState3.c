struct S { int f0; int f4; char pad[0x108]; int f110; int f114; };

void Ov050_ArmState3(struct S *p, int a)
{
    p->f4 = 3;
    p->f110 = a;
    p->f114 = 0;
}
