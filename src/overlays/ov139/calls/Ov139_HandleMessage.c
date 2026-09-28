/* Message handler of the ov139 enemy (and its byte-identical twin): a "spawned" message (kind
 * 5) starts the first, second or third +0x394 node slot's subitem (sub 0/1/2, weight 0x1000)
 * through ov107::020c08cc with the packet's payload bytes and keeps the handle; the base handler
 * always runs. (Three-case switch; 020c08cc takes six arguments -- see Ov120_Actor_HandleEvent.) */
extern void *Ov107_CreateNodeXformTaskFx24(void *taskList, void *subitem, int mode, int blend, int weight, void *payload);
extern void Ov107_AiState_OnMessage(int actor, unsigned char *msg, int param);

void Ov139_HandleMessage(int actor, unsigned char *msg, int param)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            (*(void ***)(actor + 0x394))[1] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x394))[0], 0x17, 0, 0x1000, msg + 5);
            break;
        case 1:
            (*(void ***)(actor + 0x394))[3] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x394))[2], 0x17, 0, 0x1000, msg + 5);
            break;
        case 2:
            (*(void ***)(actor + 0x394))[5] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x394))[4], 0x17, 0, 0x1000, msg + 5);
            break;
        }
    }
    Ov107_AiState_OnMessage(actor, msg, param);
}
