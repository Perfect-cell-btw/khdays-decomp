/* Tail-call Ov009_BlitTileRect with flag 1. */
extern int Ov009_BlitTileRect(int a, int b);
int Ov009_ResourceEntryCallback(int param_1) {
    return Ov009_BlitTileRect(param_1, 1);
}
