/* Looks the id up in the table at +8 of the ov005 context and feeds the result back to
 * Ov005_TagTracker_InvokeCallback; the context pointer is re-read for the second call. */
extern int Ov005_FindEntryByTag(char *ctx, unsigned int id);
extern void Ov005_TagTracker_InvokeCallback(char *ctx, int v);
extern char *data_ov005_0205b80c;

void Ov005_InvokeTagCallback(int id) {
    char *ctx = data_ov005_0205b80c;
    int v = Ov005_FindEntryByTag(ctx + 8, (unsigned short)id);
    Ov005_TagTracker_InvokeCallback(data_ov005_0205b80c + 8, v);
}
