/* Message override: message 5 for slot 0 creates the slot's node-transform effect from the packed
 * message data; then passes the message to the shared handler (Ov107_AiState_OnMessage). */

extern int Ov107_CreateNodeXformTaskFx24(int a, int b, int c, int d, int e, void *f);
extern void Ov107_AiState_OnMessage(int a, void *b, int c);

void Ov129_SpawnSlotEffectOnce(int self, unsigned char *node, int arg) {
    switch (node[2]) {
    case 5:
        if (node[3] == 0) {
        *(int *)(*(int *)(self + 0x394) + node[3] * 8 + 4) =
            Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c),
                                *(int *)(*(int *)(self + 0x394) + node[3] * 8),
                                0x17, 2, 0x2000, node + 5);
        }
        break;
    }
    Ov107_AiState_OnMessage(self, node, arg);
}
