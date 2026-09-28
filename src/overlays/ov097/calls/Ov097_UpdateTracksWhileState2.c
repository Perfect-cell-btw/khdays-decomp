extern int Sequence_UpdateTracks(void *p, void *b);

void Ov097_UpdateTracksWhileState2(int unused, char *a, void *b) {
    if (*(int *)(a + 0x0) != 2) return;
    if (Sequence_UpdateTracks(a + 0x4, b) != 0) {
        *(int *)(a + 0x0) = 0;
    }
}
