/* Play move `move` on both rigs of the ov256 actor: the +0x384 rig takes its pose from the first
 * 34-entry table (data_ov256_020d2484) and the +0x3ac rig from the second (data_ov256_020d250c),
 * each through 020ccc6c with its +0x388 / +0x3b0 work list; a negative id skips that rig. */

#include "game/enemy_common.h"

typedef struct { int id[34]; } MovePoses;

extern void Ov256_AppendWorkEntryFinalize(int rig, void *pose, int loop, void *work);
extern const MovePoses data_ov256_020d2484;
extern const MovePoses data_ov256_020d250c;

void Ov256_PlayRigMove(char *self, int move, int loop)
{
    MovePoses body = data_ov256_020d2484;
    MovePoses tail = data_ov256_020d250c;

    if (body.id[move] >= 0) {
        Ov256_AppendWorkEntryFinalize(*(int *)(self + 0x384), Ov107_PackTextureHandle(self, body.id[move]), loop, self + 0x388);
    }
    if (tail.id[move] < 0) {
        return;
    }
    Ov256_AppendWorkEntryFinalize(*(int *)(self + 0x3ac), Ov107_PackTextureHandle(self, tail.id[move]), loop, self + 0x3b0);
}
