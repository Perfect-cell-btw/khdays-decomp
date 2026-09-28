/* Ov024_MobiClip_PlayerTick -- MobiClip: per-frame tick for the active player.
 * Does nothing without a player (data_ov024_02093a20[1]). If the player has the flag at
 * +0x8be1 raised, the GFX command queue is drained once and the flag cleared -- the reload of
 * the global for the clear is deliberate, it is how the ROM reads it.
 * Then the player is stepped and the frame handed on to SoundMgr_Update. */
extern void FrameStep_UpdateTaskQueue(void);
extern void Ov024_MobiClip_StepScreenFade(int player);
extern void SoundMgr_Update(void);
extern int data_ov024_02093a20[];

void Ov024_MobiClip_PlayerTick(void) {
    int player;

    player = data_ov024_02093a20[1];
    if (player == 0) {
        return;
    }
    if (*(unsigned char *)(player + 0x8be1) != 0) {
        FrameStep_UpdateTaskQueue();
        *(unsigned char *)(data_ov024_02093a20[1] + 0x8be1) = 0;
    }
    Ov024_MobiClip_StepScreenFade(player);
    SoundMgr_Update();
}
