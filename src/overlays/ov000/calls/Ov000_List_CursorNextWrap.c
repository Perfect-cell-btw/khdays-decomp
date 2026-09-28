/* Ov000_List_CursorNextWrap -- logo scroller step (forward), ov000. Counts field[1] up;
 * on reaching 0x1c resets field[0]/field[1], else advances field[0] when it trails
 * far enough. Clamps field[0] to field[1]; refreshes the display. */
extern void PlaySound(int, int);
extern void Ov000_QueueResourceTransfers(void);
void Ov000_List_CursorNextWrap(short *s) {
    s[1]++;
    if (s[1] >= 0x1c) {
        s[1] = 0;
        s[0] = 0;
        *(int *)((char *)s + 0x60) = 0;
    } else if (s[0] + 0xa <= s[1]) {
        s[0]++;
        *(int *)((char *)s + 0x60) = 0;
    }
    if (s[1] < s[0]) {
        s[0] = s[1];
        *(int *)((char *)s + 0x60) = 0;
    }
    PlaySound(0, 0);
    Ov000_QueueResourceTransfers();
}
