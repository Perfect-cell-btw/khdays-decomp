/* Ov024_AdvanceNodeAnim -- advance the node's animation, ov024. Ticks the sub-object
 * (*node) and bumps the frame counter @+0x40. */
extern void Ov024_MobiClip_DecodeAudioEntryChecked_2(void *sub);
void Ov024_AdvanceNodeAnim(char *node) {
    Ov024_MobiClip_DecodeAudioEntryChecked_2(*(void **)node);
    *(int *)(node + 0x40) += 1;
}
