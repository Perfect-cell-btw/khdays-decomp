/* Ov024_MobiClip_CloseRenderPass -- MobiClip: close the render pass opened by Ov024_ArmAndStart.
 * The open flag lives at +0x50; if it is clear there is nothing to close. */
extern void Text_UploadTileBuffer(int p);

void Ov024_MobiClip_CloseRenderPass(int p) {
    if (*(int *)(p + 0x50) == 0) {
        return;
    }
    Text_UploadTileBuffer(p);
    *(int *)(p + 0x50) = 0;
}
