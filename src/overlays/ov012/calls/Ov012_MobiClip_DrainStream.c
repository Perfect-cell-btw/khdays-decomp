/* Ov012_MobiClip_DrainStream -- MobiClip: drain a stream in `mode`, then reset it.
 * Parks the mode in +0x74 so the lead update and the drain step see it, recomputes the lead
 * once up front, then pumps Ov012_MobiClip_PresentRecord for as long as Ov012_IsModeEntryActive says there
 * is work left. On the way out the mode and the two cursors (+0x64/+0x6c) are cleared and +0x50
 * is raised to mark the stream drained. */
extern void Ov012_MobiClip_UpdateStreamLead(int stream);
extern int  Ov012_IsModeEntryActive(int stream);
extern void Ov012_MobiClip_PresentRecord(int stream);

void Ov012_MobiClip_DrainStream(int stream, int mode) {
    *(int *)(stream + 0x74) = mode;
    Ov012_MobiClip_UpdateStreamLead(stream);
    while (Ov012_IsModeEntryActive(stream) != 0) {
        Ov012_MobiClip_PresentRecord(stream);
    }
    *(int *)(stream + 0x74) = 0;
    *(int *)(stream + 0x64) = 0;
    *(int *)(stream + 0x6c) = 0;
    *(int *)(stream + 0x50) = 1;
}
