/* Queues a switch to another BGM that remembers the interrupted track (request 5): leaving a
 * kind-1 track for a kind-2 one saves its position, and switching back to it later resumes it
 * there with a short fade-in. */

extern int SoundMgr_QueueRequest();

int SoundMgr_SwitchBgmResume(int seq, int fade) {
    return SoundMgr_QueueRequest(5, seq, fade);
}
