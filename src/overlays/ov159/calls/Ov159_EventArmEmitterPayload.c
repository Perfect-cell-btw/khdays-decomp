/* Single-case switch: `if (msg[2] == 5)` (or `== 5 && ...`) lets mwcc if-convert the
 * inner test into the outer one (ldrbeq/cmpeq); the ROM branches on both. */
extern int  Ov107_CreateNodeXformTaskFx24(int a, int b, int mode, int c, int d, int e);
extern void Ov107_AiState_OnMessage(int a, int b, int c);

void Ov159_EventArmEmitterPayload(int self, unsigned char *msg, int arg3) {
    switch (msg[2]) {
    case 5:
        if (msg[3] == 0) {
            *(int *)(*(int *)(self + 0x390) + 4) = Ov107_CreateNodeXformTaskFx24(
                *(int *)(self + 0x3c), *(int *)(*(int *)(self + 0x390)), 5, msg[4], 0x1000,
                (int)(msg + 5));
        }
        break;
    }
    Ov107_AiState_OnMessage(self, (int)msg, arg3);
}
