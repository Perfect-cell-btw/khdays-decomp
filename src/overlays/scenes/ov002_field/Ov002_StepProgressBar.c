/*
 * Ov002_StepProgressBar - advance the progress bar towards where the run
 * actually is.
 *
 * On the first pass the bar is armed: the two reward icons are taken if the
 * run has already earned them, the tick is stamped and the bar jumps straight
 * to its true length, which is the done count scaled to the width of the
 * screen.
 *
 * After that the bar creeps: one step per interval, catching up however many
 * intervals have gone by since the last pass. When it reaches the target the
 * chime plays once and the bar stops exactly on it.
 *
 * Either way, once the run has any steps at all, the two icons are taken as
 * soon as they are earned.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    char pad000[0xa0];
    void *pGoalIcon;
    void *pFullIcon;
} Ov002TextScene;

typedef struct {
    int nTotal;
    int nDone;
    int nGoal;
} Ov002Progress;

typedef struct {
    int nCurrent;
    int nTarget;
    int bSound;
    int bDirty;
    u64 llStamp;
    u64 llInterval;
} Ov002BarAnim;

extern int data_ov002_0207f62c;

extern u64 OS_GetTick(void);
extern int func_02020400(int nNumer, int nDenom);
extern void ForwardToHandlerOrCurrentObject(int a, int b, int c);

extern Ov002Progress *Ov002_GetMissionProgress(void);
extern Ov002BarAnim *Ov002_Field_GetBlock194(void);
extern void *Ov002_TriggerOnceOnFlag(void);
extern void *Ov002_UpdateFieldMusic(void);

void Ov002_StepProgressBar(void)
{
    Ov002TextScene *s;
    Ov002Progress *p;
    u64 llNow;
    Ov002BarAnim *a;

    s = *(Ov002TextScene **)((char *)&data_ov002_0207f62c + 4);
    p = Ov002_GetMissionProgress();
    a = Ov002_Field_GetBlock194();

    if (a->llStamp == 0) {
        if (p->nDone >= p->nGoal) {
            s->pGoalIcon = Ov002_TriggerOnceOnFlag();
        }
        if (p->nDone == p->nTotal) {
            s->pFullIcon = Ov002_UpdateFieldMusic();
        }
        if (p->nTotal > 0) {
            a->llStamp = OS_GetTick();
            a->nTarget = a->nCurrent =
                func_02020400(p->nDone * 0xe0, p->nTotal);
            a->bDirty = 1;
        }
    } else if (a->nTarget > a->nCurrent) {
        llNow = OS_GetTick();
        while (a->llStamp + a->llInterval <= llNow) {
            a->llStamp += a->llInterval;
            a->nCurrent++;
            if (a->nCurrent >= a->nTarget) {
                if (a->bSound != 0) {
                    ForwardToHandlerOrCurrentObject(0, 0x32, 0);
                    a->bSound = 0;
                }
                a->nCurrent = a->nTarget;
                break;
            }
        }
        a->bDirty = 1;
    }

    if (p->nTotal <= 0) {
        return;
    }
    if (s->pGoalIcon == 0 && p->nDone >= p->nGoal) {
        s->pGoalIcon = Ov002_TriggerOnceOnFlag();
    }
    if (s->pFullIcon == 0 && p->nDone == p->nTotal) {
        s->pFullIcon = Ov002_UpdateFieldMusic();
    }
}
