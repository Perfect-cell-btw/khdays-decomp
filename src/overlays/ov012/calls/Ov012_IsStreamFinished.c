/* Ov012_IsStreamFinished -- MobiClip: has this stream reached its end? (THUMB)
 * Resolves the descriptor to a length, and reports done unless the clock has caught up with it:
 * a zero length means "never done" (an open-ended stream), otherwise the current position from
 * Ov024_MobiClip_BufferedFrameCount must have reached it. If Ov012_IsRequestStateTwo rejects the resolved handle
 * outright the stream counts as done.
 * blx on 02082eb8 / 02084e68 because both are ARM.
 *
 * The redundant `pos >= len` test is load-bearing -- see Ov024_MayWaitFrames for the full
 * write-up. Short version: mwcc turns `if (c) return 0; return 1;` into the boolean `!c` and
 * then always lays the 1-block out inline, which is the mirror of the ROM. Any constant pair
 * other than (0, 1) gets the ordinary then-arm-inline layout, and a second test that mwcc can
 * prove redundant costs nothing while taking this pair out of the special case. */
extern int ScriptVm_ReadOperandInt(int owner, void *entry);
extern int Slot48_StoreAtCurrentIndex(int owner, int handle);
extern int Ov012_IsRequestStateTwo(int handle);
extern int Ov024_MobiClip_BufferedFrameCount(void);

int Ov012_IsStreamFinished(int owner, void *entry) {
    int len;
    int pos;

    len = ScriptVm_ReadOperandInt(owner, entry);
    if (Ov012_IsRequestStateTwo(Slot48_StoreAtCurrentIndex(owner, len)) == 0) {
        return 1;
    }
    if (len == 0) {
        return 0;
    }

    pos = Ov024_MobiClip_BufferedFrameCount();
    if (pos < len) {
        return 0;
    }
    if (pos >= len) {
        return 1;
    }
    return 1;
}
