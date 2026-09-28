/* While active updates the animation tracks; deactivates when they finish. */

extern unsigned short Sequence_UpdateTracks(void *p, void *b);

void Ov094_UpdateTracksWhileActive(int unused, char *a, void *b) {
    if (*(int *)(a + 0xc) != 1) return;
    if (Sequence_UpdateTracks(a + 0x10, b) != 0) {
        *(int *)(a + 0xc) = 0;
    }
}
