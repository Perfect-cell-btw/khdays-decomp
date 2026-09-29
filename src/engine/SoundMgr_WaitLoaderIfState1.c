/* In sound manager state 1, sleeps while the loader is busy. */

#include "game/engine.h"

void SoundMgr_WaitLoaderIfState1(void)
{
    if (SoundMgr_IsState1()) Loader_SleepIfBusy();
}
