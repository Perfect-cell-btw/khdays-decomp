/* Motion set of the ov235 enemy: for the given motion index, the three animated parts (+0x384,
 * +0x38c, +0x394, each with its binding at the next word) take the resource listed in
 * data_ov235_020d22fc / 020d2398 / 020d2434 (Ov235_AppendWorkEntry) and restart channel 0 -- channel
 * 2 too for the third part -- with the given loop mode. */

#include "game/enemy_common.h"

typedef struct { int id[39]; } MotionTable;

extern void Ov235_AppendWorkEntry(int part, void *res, int binding);
extern void SetSubitemState(int obj, int channel, int a, int b);
extern MotionTable data_ov235_020d22fc;
extern MotionTable data_ov235_020d2398;
extern MotionTable data_ov235_020d2434;

void Ov235_SetMotion(char *self, int motion, int loop)
{
    MotionTable body = data_ov235_020d22fc;
    MotionTable head = data_ov235_020d2398;
    MotionTable wings = data_ov235_020d2434;

    Ov235_AppendWorkEntry(*(int *)(self + 0x384), Ov107_PackTextureHandle(self, body.id[motion]), *(int *)(self + 0x388));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, loop);
    Ov235_AppendWorkEntry(*(int *)(self + 0x38c), Ov107_PackTextureHandle(self, head.id[motion]), *(int *)(self + 0x390));
    SetSubitemState(*(int *)(self + 0x38c), 0, 0, loop);
    Ov235_AppendWorkEntry(*(int *)(self + 0x394), Ov107_PackTextureHandle(self, wings.id[motion]), *(int *)(self + 0x398));
    SetSubitemState(*(int *)(self + 0x394), 0, 0, loop);
    SetSubitemState(*(int *)(self + 0x394), 2, 0, loop);
}
