/* Deactivates the node outside modes 48/49; while active updates its animation tracks. */

extern void Sequence_UpdateTracks(void *p, int arg);

void Ov079_UpdateTracksByMode(char *obj, char *b, int c) {
    int mode = *(int *)(obj + 0x6bc);
    if (mode != 48 && mode != 49) {
        *(int *)(b + 0x124) = 0;
    }
    if (*(int *)(b + 0x124) != 1) return;
    Sequence_UpdateTracks(b + 0x128, c);
}
