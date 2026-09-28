/* Sends a sync request message (kind 8) with the local player and the request's values; stores the
 * message handle. */

extern int Session_GetLocalPlayerIndex(void);
extern int func_02031384(int arg0, void *arg1, int arg2);

struct marshal_020b0eb8 {
    unsigned char f0 : 3;
    unsigned char f3 : 3;
    unsigned char f6 : 2;
    unsigned char pad[3];
};

void Ov022_SendSyncRequest(int param_1) {
    struct marshal_020b0eb8 m;
    m.f0 = Session_GetLocalPlayerIndex();
    m.f3 = *(unsigned char *)(param_1 + 1);
    m.f6 = *(unsigned char *)(param_1 + 2);
    *(short *)(param_1 + 0x36) = func_02031384(8, &m, 1);
}
