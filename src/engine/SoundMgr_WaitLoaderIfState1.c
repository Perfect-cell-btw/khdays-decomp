/* In sound manager state 1, sleeps while the loader is busy. */

extern int SoundMgr_IsState1();
extern void Loader_SleepIfBusy();

void SoundMgr_WaitLoaderIfState1(void)
{
    if (SoundMgr_IsState1()) Loader_SleepIfBusy();
}
