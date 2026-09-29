/* Single-case switch: `msg[2] == 5 && msg[3] == 0` lets mwcc if-convert the second test
 * into the first (ldrbeq/cmpeq); the ROM branches on both.
 * Ov107_CreateSpawnTask takes FIVE arguments (the fifth on the stack); Ghidra shows six. */
extern int  Ov107_CreateSpawnTask();
extern void Ov117_UnlinkHeldNode(int self);
extern void Ov107_AiState_OnMessage(int self, int msg, int c);

void Ov117_SpawnAuraOnTag5(int self, int msg, int c) {
    switch (*(unsigned char *)(msg + 2)) {
    case 5:
        if (*(unsigned char *)(msg + 3) == 0) {
            if (*(int *)(self + 0x390) == 0) {
                *(int *)(self + 0x390) = Ov107_CreateSpawnTask(self, 0x120, 5, 1, self + 0xa0);
            } else {
                Ov117_UnlinkHeldNode(self);
            }
        }
        break;
    }
    Ov107_AiState_OnMessage(self, msg, c);
}
