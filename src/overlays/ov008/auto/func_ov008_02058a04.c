extern int data_ov008_02090f1c;

/* Clear DISPCNT bits 13-15 of engine A (the WIN0, WIN1 and OBJ window enables). */
void func_ov008_02058a04(void)
{
    volatile unsigned int *reg_dispcnt = (volatile unsigned int *)0x04000000;
    *reg_dispcnt &= ~0xe000;
    data_ov008_02090f1c = 0;
}
