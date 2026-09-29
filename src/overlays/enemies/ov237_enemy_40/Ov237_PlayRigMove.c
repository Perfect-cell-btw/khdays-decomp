/* Play move `move` on both rigs of the ov237 actor: the +0x384 rig takes its pose from the first
 * 25-entry table (data_ov237_020d1a6c) and the +0x3ac rig from the second (data_ov237_020d1ad0),
 * each through 020cd0b0 with its +0x388 / +0x3b0 work list; a negative id skips that rig. */

#include "game/enemy_common.h"

typedef struct { int id[25]; } MovePoses;

extern void Ov237_AppendWorkEntryFinalize(int rig, void *pose, int loop, void *work);
extern const MovePoses data_ov237_020d1a6c;
extern const MovePoses data_ov237_020d1ad0;

void Ov237_PlayRigMove(char *self, int move, int loop)
{
    MovePoses body = data_ov237_020d1a6c;
    MovePoses tail = data_ov237_020d1ad0;

    if (body.id[move] >= 0) {
        Ov237_AppendWorkEntryFinalize(*(int *)(self + 0x384), Ov107_PackTextureHandle(self, body.id[move]), loop, self + 0x388);
    }
    if (tail.id[move] < 0) {
        return;
    }
    Ov237_AppendWorkEntryFinalize(*(int *)(self + 0x3ac), Ov107_PackTextureHandle(self, tail.id[move]), loop, self + 0x3b0);
}
