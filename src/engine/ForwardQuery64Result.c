/* Enqueues the global surface update and hands its result to the sound manager's update. */

extern long long Gfx_EnqueueSurface(int a);
extern void SoundMgr_Update(long long v);
extern int data_0204be08[];

void ForwardQuery64Result(void) {
    SoundMgr_Update(Gfx_EnqueueSurface(data_0204be08[1] + 0xc));
}
