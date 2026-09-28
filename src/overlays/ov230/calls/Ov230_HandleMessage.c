/* Message handler of the ov230 enemy (+0x1c): kind-5 message 0 plays effect pair 0 (+0x38c
 * resource, handle kept at +0x390, kind 0x17) on the +0xa0 pose with the message's +4 byte; every
 * message then goes to the common handler. (`if (msg[3] == 0)` inside a one-case switch keeps the
 * ROM's two branches instead of an if-converted pair.) */
extern int  Ov107_CreateNodeBodyTask(int a, int b, int mode, int anchor, int e, int f);
extern void Ov107_AiState_OnMessage(int a, int b, int c);

void Ov230_HandleMessage(int self, unsigned char *msg, int arg3) {
    switch (msg[2]) {
    case 5:
        if (msg[3] == 0) {
            *(int *)(self + msg[3] * 8 + 0x390) = Ov107_CreateNodeBodyTask(
                *(int *)(self + 0x3c), *(int *)(self + msg[3] * 8 + 0x38c), 0x17,
                self + 0xa0, msg[4], 0);
        }
        break;
    }
    Ov107_AiState_OnMessage(self, (int)msg, arg3);
}
