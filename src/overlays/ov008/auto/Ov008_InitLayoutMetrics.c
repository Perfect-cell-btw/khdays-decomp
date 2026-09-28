/* Sets the layout metrics (item scales 0xb33/0xab8, span 0x4800). */

void Ov008_InitLayoutMetrics(int *obj)
{
    obj[5] = 0xb33;
    obj[6] = 0xab8;
    obj[8] = 0xb33;
    obj[9] = 0xab8;
    obj[10] = 0x4800;
}
