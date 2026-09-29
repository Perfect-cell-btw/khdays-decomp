/* Ov245_PoseSyncChain -- pose sync: runs the +0x3a0 item's motion (020c9ec8 with the argument),
 * the base sync (020c6980), then copies the +0x39c source's +4 transform (44 bytes) into the
 * +0x38c item's +0x10 and that one's +0x10 into the +0x388 target's +0x10. Codegen: typed struct
 * member copies (destination address evaluated first, ip before lr). */

#include "game/enemy_common.h"

typedef struct { int m[11]; } Pose44;
struct Ov245Item { char pad[0x10]; Pose44 pose; };
struct Ov245Src { char pad[4]; Pose44 pose; };

extern void Ov107_ProcessObjectTick(int self, int a);

void Ov245_PoseSyncChain(int self, int a) {
    Ov107_RefreshAndSelectChild(*(int *)(self + 0x3a0), a);
    Ov107_ProcessObjectTick(self, a);
    ((struct Ov245Item *)*(int *)(self + 0x38c))->pose = ((struct Ov245Src *)*(int *)(self + 0x39c))->pose;
    ((struct Ov245Item *)**(int **)(self + 0x388))->pose = ((struct Ov245Item *)*(int *)(self + 0x38c))->pose;
}
