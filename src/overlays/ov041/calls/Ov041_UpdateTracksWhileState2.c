/* In state 2 updates the animation tracks; resets when they finish. */

extern int Sequence_UpdateTracks(void *p, void *b);

void Ov041_UpdateTracksWhileState2(int unused, char *a, void *b) {
    if (*(int *)(a + 0x0) != 2) return;
    if (Sequence_UpdateTracks(a + 0x4, b) != 0) {
        *(int *)(a + 0x0) = 0;
    }
}
