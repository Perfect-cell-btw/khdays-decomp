/* Return 1 if any slot 0..count-1 passes Ov008_GetCtxWord9758, else 0; count comes
 * from Ov008_GetCtxField9750. */
extern int Ov008_GetCtxField9750(void);
extern int Ov008_GetCtxWord9758(int index);

int Ov008_AnyEntryFlagged(void) {
    int count = Ov008_GetCtxField9750();
    unsigned short i = 0;
    if (count != 0) {
        do {
            if (Ov008_GetCtxWord9758(i) != 0) return 1;
            i++;
        } while ((unsigned int)count > i);
    }
    return 0;
}
