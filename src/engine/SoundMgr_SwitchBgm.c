/* Queues a switch to another BGM (request 4): the current track fades out over `fade` frames,
 * then `seq` starts. */

extern int SoundMgr_QueueRequest();

int SoundMgr_SwitchBgm(int seq, int fade) {
    return SoundMgr_QueueRequest(4, seq, fade);
}
