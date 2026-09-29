/* Message handler of the ov153 enemy (x3: ov153/154/155): a kind-5 / sub-0 message attaches the
 * two +0x394 sub-items (slots 0 and 2, handles into slots 1 and 3) to the actor's +0x3c model
 * with mode 0x17 at the +0x39c anchor; everything then falls through to the ov107 base handler. */
extern int Ov107_CreateNodeBodyTask(int resource, int item, int mode, int anchor, int e, int f);
extern void Ov107_AiState_OnMessage(int self, int msg, int size);

void Ov153_HandleMessage(int self, int msg, int size)
{
    if (*(unsigned char *)(msg + 2) == 5) {
        switch (*(unsigned char *)(msg + 3)) {
        case 0:
            *(int *)(*(int *)(self + 0x394) + 4) =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), **(int **)(self + 0x394), 0x17,
                                    self + 0x39c, 0, 0);
            *(int *)(*(int *)(self + 0x394) + 0xc) =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), *(int *)(*(int *)(self + 0x394) + 8),
                                    0x17, self + 0x39c, 0, 0);
            break;
        }
    }
    Ov107_AiState_OnMessage(self, msg, size);
}
