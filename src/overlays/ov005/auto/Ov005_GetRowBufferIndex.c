/* Map a result text entry ID to its row buffer slot; other IDs have no buffer. */
int Ov005_GetRowBufferIndex(int entryId) {
    int index = -1;
    switch (entryId) {
    case 9: index = 0; break;
    case 10: index = 1; break;
    case 11: index = 2; break;
    }
    return index;
}
