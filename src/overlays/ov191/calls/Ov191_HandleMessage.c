/* Message handler of the ov191 enemy (x3: ov191/192/193): a "spawned" message (kind 5) starts
 * the first node slot's subitem (sub 0, weight 0x1000) or the second's (sub 1, weight 0x800)
 * through ov107::020c08cc with the packet's payload bytes and keeps the handle; the base handler
 * always runs. (Two-case switch; 020c08cc takes six arguments -- see Ov120_Actor_HandleEvent.) */
extern void *Ov107_CreateNodeXformTaskFx24(void *taskList, void *subitem, int mode, int blend, int weight, void *payload);
extern void Ov107_AiState_OnMessage(int actor, unsigned char *msg, int param);

void Ov191_HandleMessage(int actor, unsigned char *msg, int param)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            (*(void ***)(actor + 0x390))[1] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x390))[0], 0x17, 0, 0x1000, msg + 5);
            break;
        case 1:
            (*(void ***)(actor + 0x390))[3] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x390))[2], 0x17, 0, 0x800, msg + 5);
            break;
        }
    }
    Ov107_AiState_OnMessage(actor, msg, param);
}
