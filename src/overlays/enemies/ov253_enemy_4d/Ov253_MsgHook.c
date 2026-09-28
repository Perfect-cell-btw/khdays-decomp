/* Ov253_MsgHook -- message hook: a kind 0 message stores its +0x24 handle at +0x44c and
 * its +0x28 byte at +0x450 when it changed; a kind 5 message aimed at slot 0 spawns the +0x468
 * block's first effect child (020c08cc, kind 5, scale 1.0, payload at byte 5) into its +4, and
 * aimed at slot 1 spawns the second one (020c09a0, kind 5, at the actor's +0xa0) into its +0xc.
 * Then the message goes to the base hook (020c7500). */
extern int Ov107_CreateNodeXformTaskFx24(int list, int parent, int kind, int a, int scale, unsigned char *payload);
extern int Ov107_CreateNodeBodyTask(int list, int parent, int kind, void *pos, int a, int b);
extern int Ov107_AiState_OnMessage(int self, unsigned char *msg, int extra);

struct Ov253Pair { int pEffect; int pChild; };

int Ov253_MsgHook(int self, unsigned char *msg, int extra) {
    if (msg[2] == 0) {
        *(int *)(self + 0x44c) = *(int *)(msg + 0x24);
        if (*(signed char *)(self + 0x400 + 0x50) != *(signed char *)(msg + 0x28)) {
            *(unsigned char *)(self + 0x450) = *(signed char *)(msg + 0x28);
        }
    } else if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            (*(struct Ov253Pair **)(self + 0x468))[0].pChild =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Ov253Pair **)(self + 0x468))[0].pEffect, 5, 0, 0x1000, msg + 5);
            break;
        case 1:
            (*(struct Ov253Pair **)(self + 0x468))[1].pChild =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), (*(struct Ov253Pair **)(self + 0x468))[1].pEffect, 5, (void *)(self + 0xa0), 0, 0);
            break;
        }
    }
    return Ov107_AiState_OnMessage(self, msg, extra);
}
