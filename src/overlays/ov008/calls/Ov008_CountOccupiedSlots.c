extern int *Slot4_GetIfOccupied(int index);

unsigned int Ov008_CountOccupiedSlots(void)
{
    unsigned short count = 0;
    int i = 0;

    while (i < 4) {
        int *entry = Slot4_GetIfOccupied(i);

        if (entry != 0 && *entry != 0) {
            count++;
        }
        i++;
    }

    return count;
}
