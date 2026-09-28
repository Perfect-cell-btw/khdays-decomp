extern int Session_GetLocalPlayerIndex(void);
extern int *Slot4_GetIfOccupied(int);
int Ov008_GetLocalPlayerCharacter(void)
{
    int *entry = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex());
    if (entry != 0) {
        return entry[1];
    }
    return 0;
}
