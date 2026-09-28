/* Ov024_MobiClip_ArenaInitData -- MobiClip: hand the fast-memory arena its backing store.
 * The arena descriptor is data_ov024_0209bb30; this points it at `base` with `size` bytes
 * (rounded down to a word) and clears the cursor and cached-block fields. This is what
 * Ov024_MobiClip_GetDecoderCodeCached and Ov024_MobiClip_GetSatTable5BitCached later carve the ITCM blob and the saturation
 * table out of. */
extern int data_ov024_0209bb30[];

void Ov024_MobiClip_ArenaInitData(int base, unsigned int size) {
    data_ov024_0209bb30[4] = base;
    data_ov024_0209bb30[3] = size & 0xfffffffc;
    data_ov024_0209bb30[1] = 0;
    data_ov024_0209bb30[0] = 0;
    data_ov024_0209bb30[8] = 0;
}
