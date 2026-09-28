/* Runs one step of the script scheduler (SoundMgr_Update) and reports whether it is idle (not in
 * state 1, SoundMgr_IsState1). */
#pragma thumb on
extern void SoundMgr_Update(void);
extern int SoundMgr_IsState1(void);

enum { SCHED_BUSY = 0, SCHED_IDLE = 1 };

int Script_StepAndIsIdle(void)
{
    SoundMgr_Update();
    return SoundMgr_IsState1() != 0 ? SCHED_BUSY : SCHED_IDLE;
}
