/* Play move `move` on both rigs of the ov258 actor: the +0x384 rig takes its pose from the first
 * 16-entry table (data_ov258_020d16f4) and the +0x3ac rig from the second (data_ov258_020d1734),
 * each through 020ccf40 with its +0x388 / +0x3b0 work list; a negative id skips that rig. */

#include "game/enemy_common.h"

typedef struct { int id[16]; } MovePoses;

extern void Ov258_AppendWorkEntryFinalize(int rig, void *pose, int loop, void *work);
extern const MovePoses data_ov258_020d16f4;
extern const MovePoses data_ov258_020d1734;

void Ov258_PlayRigMove(char *self, int move, int loop)
{
    MovePoses body = data_ov258_020d16f4;
    MovePoses tail = data_ov258_020d1734;

    if (body.id[move] >= 0) {
        Ov258_AppendWorkEntryFinalize(*(int *)(self + 0x384), Ov107_PackTextureHandle(self, body.id[move]), loop, self + 0x388);
    }
    if (tail.id[move] < 0) {
        return;
    }
    Ov258_AppendWorkEntryFinalize(*(int *)(self + 0x3ac), Ov107_PackTextureHandle(self, tail.id[move]), loop, self + 0x3b0);
}
