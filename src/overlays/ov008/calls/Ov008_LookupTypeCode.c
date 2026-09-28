/* Advance Session_GetLocalPlayerIndex, then map the current Slot4_GetIfOccupied slot to a priority
 * table, storing its index. */

extern void Session_GetLocalPlayerIndex(void *arg0);
extern int *Slot4_GetIfOccupied(void);
extern int data_ov008_0208e8a4[];

int Ov008_LookupTypeCode(int *out)
{
    int result = 0xa;
    int *entry;

    Session_GetLocalPlayerIndex(out);
    entry = Slot4_GetIfOccupied();

    if (entry != 0) {
        result = data_ov008_0208e8a4[entry[1]];
    }

    if (out != 0) {
        *out = entry[1];
    }

    return result;
}
