/* Splits a count of seconds into hours, minutes and seconds (any of the outputs may be NULL); past
 * 999 hours shows 999:;;. */

void Ov000_SplitTimeUnitsHMS(unsigned int value, unsigned short *hours, char *minutes, char *seconds)
{
    if (seconds != 0)
        *seconds = (char)(value % 60);
    if (minutes != 0)
        *minutes = (char)((value / 60) % 60);
    if (hours != 0)
        *hours = (unsigned short)(value / 3600);
    if (*hours > 999) {
        *hours = 999;
        *minutes = ';';
        *seconds = ';';
    }
}
