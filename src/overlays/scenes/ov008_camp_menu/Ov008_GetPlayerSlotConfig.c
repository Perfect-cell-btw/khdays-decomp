/* Ov008_GetPlayerSlotConfig -- read the current player's slot config out of the default table, ov008.
 * Copies the 20-word default config template (data_ov008_0208f328) onto the stack, then for the
 * current player's save accessor (Slot4_GetIfOccupied) returns, via the optional out-params, the
 * template entry selected by the accessor's index (accessor+4) and that raw index. */
struct T20 { int w[20]; };
extern int Session_GetLocalPlayerIndex(void);
extern int Slot4_GetIfOccupied(int player);
extern struct T20 data_ov008_0208f328;

void Ov008_GetPlayerSlotConfig(int *outValue, int *outIndex) {
    struct T20 tbl = data_ov008_0208f328;
    int slot = Slot4_GetIfOccupied(Session_GetLocalPlayerIndex());
    if (slot != 0) {
        if (outValue != 0) {
            *outValue = tbl.w[*(int *)(slot + 4)];
        }
        if (outIndex != 0) {
            *outIndex = *(int *)(slot + 4);
        }
    }
}
