/* Queues a sound-manager request of a fixed kind with the two arguments. */

extern int SoundMgr_QueueRequest();

int func_02033758(int arg0, int arg1) {
    return SoundMgr_QueueRequest(4, arg0, arg1);
}
