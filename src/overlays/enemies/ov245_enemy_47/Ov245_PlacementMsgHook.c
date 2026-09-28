/* Ov245_PlacementMsgHook -- message hook: a kind-0 message, unless the +0x50 mode is 1, unpacks the
 * three 24-bit positions at bytes 0x26..0x2e into the +0x3b4 translation, applies it to the +0x3a4
 * placement (0203ca30) with the halfword scale at 0x24 (0203ca9c); a kind-5 message spawns a
 * kind-0x17 child (scale 2.5, payload msg+5) under +0x3e0 slot 0/1, or a kind-5 child at the
 * +0x3a4 placement (020c09a0) under slot 2, each landing in the slot's +4. Then the base hook. */
struct Ov245Slots3e0 { char pad[0x3e0]; struct { int pEffect; int pChild; } slots[3]; };

extern void Srt_SetTranslation(void *srt, void *translation);
extern void Srt_SetScaleUniform(void *srt, int scale);
extern int Ov107_CreateNodeXformTaskFx24(int list, int parent, int kind, int a, int scale, unsigned char *payload);
extern int Ov107_CreateNodeBodyTask(int list, int parent, int kind, void *at, int a, int b);
extern int Ov107_AiState_OnMessage(int self, unsigned char *msg, int extra);

int Ov245_PlacementMsgHook(int self, unsigned char *msg, int extra) {
    int rawZ;
    int rawY;
    int rawX;

    if (msg[2] == 0) {
        if (*(int *)(self + 0x50) != 1) {
            ((char *)&rawX)[3] = msg[0x26];
            ((char *)&rawX)[2] = msg[0x27];
            ((char *)&rawX)[1] = msg[0x28];
            *(int *)(self + 0x3b4) = rawX >> 8;
            ((char *)&rawY)[3] = msg[0x29];
            ((char *)&rawY)[2] = msg[0x2a];
            ((char *)&rawY)[1] = msg[0x2b];
            *(int *)(self + 0x3b8) = rawY >> 8;
            ((char *)&rawZ)[3] = msg[0x2c];
            ((char *)&rawZ)[2] = msg[0x2d];
            ((char *)&rawZ)[1] = msg[0x2e];
            *(int *)(self + 0x3bc) = rawZ >> 8;
            Srt_SetTranslation((void *)(self + 0x3a4), (void *)(self + 0x3b4));
            Srt_SetScaleUniform((void *)(self + 0x3a4), *(short *)(msg + 0x24));
        }
    } else if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
        case 1:
            ((struct Ov245Slots3e0 *)self)->slots[msg[3]].pChild =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), ((struct Ov245Slots3e0 *)self)->slots[msg[3]].pEffect,
                                    0x17, 0, 0x2800, msg + 5);
            break;
        case 2:
            ((struct Ov245Slots3e0 *)self)->slots[msg[3]].pChild =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), ((struct Ov245Slots3e0 *)self)->slots[msg[3]].pEffect,
                                    5, (void *)(self + 0x3a4), 0, 1);
            break;
        }
    }
    return Ov107_AiState_OnMessage(self, msg, extra);
}
