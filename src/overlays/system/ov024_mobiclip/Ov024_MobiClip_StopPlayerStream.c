/* Ov024_MobiClip_StopPlayerStream -- MobiClip: stop the player's stream, in the mode the descriptor asks for.
 * The stream hangs off the player at +0x128 -> +0xc. ByteCode_ResolveOperand turns the descriptor into the
 * drain mode, then the stream is quiesced (020835d8), drained in that mode, and torn down
 * (02083ccc). THUMB; all three tail calls are blx because their targets are ARM. */
extern int ByteCode_ResolveOperand(int owner, void *desc);
extern void Ov024_ArmAndStart(int stream);
extern void Ov024_MobiClip_DrainStream(int stream, int mode);
extern void Ov024_MobiClip_CloseRenderPass(int stream);

int Ov024_MobiClip_StopPlayerStream(int player, void *desc) {
    int mode;
    int stream;

    mode = ByteCode_ResolveOperand(player, desc);
    stream = *(int *)(*(int *)(player + 0x128) + 0xc);
    Ov024_ArmAndStart(stream);
    Ov024_MobiClip_DrainStream(stream, mode);
    Ov024_MobiClip_CloseRenderPass(stream);
    return 1;
}
