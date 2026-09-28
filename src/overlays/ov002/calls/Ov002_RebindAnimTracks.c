/* Rebind and seek every track of an animation at once.
 *
 * Walks the five tracks and skips any whose table entry, the halfword at
 * +0xe0 indexed by the track, is not positive. A live track is rebound to that
 * same table with the caller's blend and then seeked to the caller's frame, so
 * the whole animation restarts in step. This is the shared entry the area
 * overlays reach through their common 0207fa40 wrapper.
 */
typedef unsigned short u16;

/* The blend argument is a short, the same signature proved on
   Ov002_ApplyAnimMode, so the narrowing belongs to the call rather than to a
   cast here. */
extern void BindAnimTrack(void *pAnim, u16 nTrack, void *pTable, short nBlend);
extern void Anim_SetFrameWrapped(void *pAnim, u16 nTrack, int nFrame);

/* Rebind and seek every track of an animation that has a table entry. */
void Ov002_RebindAnimTracks(short *pAnim, int nBlend, int nFrame) {
    int nTrack;

    for (nTrack = 0; nTrack < 5; nTrack++) {
        u16 t = (u16)nTrack;

        if (pAnim[t + 0x70] > 0) {
            BindAnimTrack(pAnim, t, pAnim + 0x70, nBlend);
            Anim_SetFrameWrapped(pAnim, (u16)nTrack, nFrame);
        }
    }
}
