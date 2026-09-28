/* Ov025_CopyActiveHitToCursor -- copy the active touch/hit entry into the menu's cursor record, ov025.
 * Snapshots the hit table (Touch_GetRecentSamples, four 8-byte entries of four shorts) into a stack
 * buffer, scans it backwards for the newest entry whose flag halfword (w[3]) is 0 and copies
 * that entry into the shared cursor record. If none qualifies, the oldest entry is copied.
 *
 * The buffer is FOUR entries, not five -- the ROM reserves 0x20 bytes of frame. `i` is declared
 * before the count so the count lands in ip and the loop counter in r3, as the ROM colours them. */
struct HitEntry { unsigned short w[4]; };

extern int  Touch_GetRecentSamples(int buf);
extern void MI_CpuCopy8(unsigned short *src, unsigned short *dst, int size);
extern int  data_ov025_020b5754;

void Ov025_CopyActiveHitToCursor(void) {
    struct HitEntry buf[4];
    int i;
    int n1 = Touch_GetRecentSamples((int)buf) - 1;

    for (i = n1; i >= 0; i--) {
        if (buf[i].w[3] == 0) {
            MI_CpuCopy8((unsigned short *)&buf[i], (unsigned short *)data_ov025_020b5754, 8);
            return;
        }
    }
    MI_CpuCopy8((unsigned short *)&buf[n1], (unsigned short *)data_ov025_020b5754, 8);
}
