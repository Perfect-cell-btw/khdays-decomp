/* Motion set of the ov255 enemy: the motion index picks a resource from the two 35-entry tables
 * (body, data_ov255_020d2a08, for the +0x384 rig with the +0x388 binding; head,
 * data_ov255_020d2a94, for the +0x38c rig with +0x390), each rig restarts channel 0 with the loop
 * flag and the head also restarts channel 2. */

#include "game/enemy_common.h"

typedef struct { int id[35]; } MotionTable;

extern void Ov255_AppendWorkEntry(int part, void *res, int binding);
extern void SetSubitemState(int obj, int channel, int a, int b);
extern MotionTable data_ov255_020d2a08;
extern MotionTable data_ov255_020d2a94;

void Ov255_SetMotion(char *self, int motion, int loop)
{
    MotionTable body = data_ov255_020d2a08;
    MotionTable head = data_ov255_020d2a94;

    Ov255_AppendWorkEntry(*(int *)(self + 0x384), Ov107_PackTextureHandle(self, body.id[motion]), *(int *)(self + 0x388));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, loop);
    Ov255_AppendWorkEntry(*(int *)(self + 0x38c), Ov107_PackTextureHandle(self, head.id[motion]), *(int *)(self + 0x390));
    SetSubitemState(*(int *)(self + 0x38c), 0, 0, loop);
    SetSubitemState(*(int *)(self + 0x38c), 2, 0, loop);
}
