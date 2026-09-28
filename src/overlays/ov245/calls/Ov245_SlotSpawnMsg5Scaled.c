/* Ov245_SlotSpawnMsg5Scaled -- message hook for kind-5 messages on the +0x3a4 slot list: takes a copy
 * of the actor's +0xa0 placement scaled by 0.6 (0203ca9c); sub-kind 0 spawns a kind-0x17 child
 * under slot msg[4] (flag 2 for slot 1, scale 1.5, payload msg+5); sub-kind 1 spawns a kind-5
 * child under slot 2 at scale 0.6; sub-kinds 2/3 spawn a kind-5 child under slot msg[3]+1 at the
 * scaled placement (020c0794). Each child lands in its slot's +4. Then the base hook (020c7500). */
typedef struct { int m[11]; } Pose44;
struct Ov245Slot { int pEffect; int pChild; };

extern void Srt_SetScaleUniform(void *srt, int scale);
extern int Ov107_CreateNodeXformTaskFx24(int list, int parent, int kind, int a, int scale, unsigned char *payload);
extern int Ov107_CreateNodeXformTask(int list, int parent, int kind, int a, Pose44 *pose);
extern int Ov245_BindMotion2(int self, unsigned char *msg, int extra);
extern int Ov107_AiState_OnMessage(int self, unsigned char *msg, int extra);

int Ov245_SlotSpawnMsg5Scaled(int self, unsigned char *msg, int extra) {
    Pose44 pose;

    if (msg[2] == 5) {
        pose = *(Pose44 *)(self + 0xa0);
        Srt_SetScaleUniform(&pose, 0x999);
        switch (msg[3]) {
        case 0:
            (*(struct Ov245Slot **)(self + 0x3a4))[msg[4]].pChild =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Ov245Slot **)(self + 0x3a4))[msg[4]].pEffect,
                                    0x17, (unsigned char)(msg[4] == 1 ? 2 : 0), 0x1800, msg + 5);
            break;
        case 1:
            (*(struct Ov245Slot **)(self + 0x3a4))[2].pChild =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Ov245Slot **)(self + 0x3a4))[2].pEffect,
                                    5, 0, 0x999, msg + 5);
            break;
        case 2:
        case 3:
            (*(struct Ov245Slot **)(self + 0x3a4))[msg[3] + 1].pChild =
                Ov107_CreateNodeXformTask(*(int *)(self + 0x3c), (*(struct Ov245Slot **)(self + 0x3a4))[msg[3] + 1].pEffect,
                                    5, 0, &pose);
            break;
        }
    }
    return Ov107_AiState_OnMessage(self, msg, extra);
}
