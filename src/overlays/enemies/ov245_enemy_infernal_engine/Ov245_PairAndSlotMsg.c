/* Ov245_PairAndSlotMsg -- message hook: a kind-0 message outside state 1 copies its two +0x24
 * halfwords into the actor's +0x4d0 pair; a kind-5 message aimed at slot 0 spawns the slot's
 * +0x4dc effect child (020c08cc, kind 0x15, scale 1.0, payload at byte 5) into +0x4e0; then
 * the default handler (020c7500) runs. */
struct Ov245Pair { char pad[0x4d0]; int pair[2]; };
struct Ov245Slots { char pad[0x4dc]; struct { int pEffect; int pChild; } slots[1]; };

extern int Ov107_CreateNodeXformTaskFx24(int list, int parent, int kind, int a, int scale, unsigned char *payload);
extern int Ov107_AiState_OnMessage(int self, unsigned char *msg, int extra);

int Ov245_PairAndSlotMsg(int self, unsigned char *msg, int extra) {
    int i;

    if (msg[2] == 0) {
        if (*(int *)(self + 0x50) != 1) {
            for (i = 0; i < 2; i++) {
                ((struct Ov245Pair *)self)->pair[i] = ((short *)(msg + 0x24))[i];
            }
        }
    } else {
        switch (msg[2]) {
        case 5:
            if (msg[3] == 0) {
                ((struct Ov245Slots *)self)->slots[msg[3]].pChild =
                    Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), ((struct Ov245Slots *)self)->slots[msg[3]].pEffect, 0x15, 0, 0x1000, msg + 5);
            }
            break;
        }
    }
    return Ov107_AiState_OnMessage(self, msg, extra);
}
