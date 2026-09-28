/* Ov245_SlotSpawnMsg4 -- message hook for kind-5 messages: slots 0 and 1 spawn the slot's
 * +0x394 effect child (020c08cc, kind 0x15, scale 1.0, payload at byte 5) into +0x398 and, for
 * slot 0, re-link the actor (020c0b14 with 1); slot 2 spawns a kind-5 child at the actor's
 * +0xa0 placement (020c09a0, flags 0/1). Then the state filter (020cc8a4). */
struct Ov245Slots { char pad[0x394]; struct { int pEffect; int pChild; } slots[3]; };

extern int Ov107_CreateNodeXformTaskFx24(int list, int parent, int kind, int a, int scale, unsigned char *payload);
extern void Ov107_ForwardVisibleEvent(int self, int a);
extern int Ov107_CreateNodeBodyTask(int list, int parent, int kind, void *at, int a, int b);
extern int Ov245_FilterStateMsg(int self, unsigned char *msg, int extra);

int Ov245_SlotSpawnMsg4(int self, unsigned char *msg, int extra) {
    switch (msg[2]) {
    case 5:
        switch (msg[3]) {
        case 0:
        case 1:
            ((struct Ov245Slots *)self)->slots[msg[3]].pChild =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), ((struct Ov245Slots *)self)->slots[msg[3]].pEffect, 0x15, 0, 0x1000, msg + 5);
            if (msg[3] == 0) {
                Ov107_ForwardVisibleEvent(self, 1);
            }
            break;
        case 2:
            ((struct Ov245Slots *)self)->slots[msg[3]].pChild =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), ((struct Ov245Slots *)self)->slots[msg[3]].pEffect, 5,
                                    (void *)(self + 0xa0), 0, 1);
            break;
        }
        break;
    }
    return Ov245_FilterStateMsg(self, msg, extra);
}
