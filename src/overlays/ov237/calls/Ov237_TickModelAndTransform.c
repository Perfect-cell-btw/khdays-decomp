extern void Ov107_RefreshAndSelectChild(int node);
extern void Sequence_UpdateTracks(unsigned short *anim, int frame);
extern void Ov107_ProcessObjectTick(int obj, int frame);
/* Per-frame tick: refresh the child node (+0x3d8), advance the animation held by the model
 * (*(obj+0x3e4))+0x88, then run the shared transform update. */
void Ov237_TickModelAndTransform(int obj, int frame) {
    Ov107_RefreshAndSelectChild(*(int *)(obj + 0x3d8));
    Sequence_UpdateTracks(*(unsigned short **)(*(int *)(obj + 0x3e4) + 0x88), frame);
    Ov107_ProcessObjectTick(obj, frame);
}
