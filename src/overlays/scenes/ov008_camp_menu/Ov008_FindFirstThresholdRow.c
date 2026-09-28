/* Returns the first threshold row whose limit is above the value (0 when none). */

extern unsigned char data_ov008_0208ee84[];

int Ov008_FindFirstThresholdRow(unsigned int value)
{
    unsigned short i = 0;

    do {
        if (value < *(unsigned short *)(data_ov008_0208ee84 + i * 8)) {
            return i;
        }

        i++;
    } while (i < 0x38);

    return 0;
}
