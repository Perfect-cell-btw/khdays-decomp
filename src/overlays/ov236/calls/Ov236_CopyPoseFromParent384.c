/* Ov236_CopyPoseFromParent384 -- twin of Ov278_CopyPoseFromParent394, reading the pose block from the parent at
 * +0x384 instead of +0x394. Same array-index-with-folded-offset form. */
extern void Ov107_SetStatusAndEmit(int obj, int mode);
extern void Ov107_HandleRegionEvent(int obj, int arg);

void Ov236_CopyPoseFromParent384(int obj, int arg) {
    int i;
    for (i = 0; i < 4; i++) {
        ((int *)obj)[i + 0x6d] = ((int *)*(int *)(obj + 0x384))[i + 0x6d];
    }
    Ov107_SetStatusAndEmit(obj, 2);
    Ov107_HandleRegionEvent(obj, arg);
}
