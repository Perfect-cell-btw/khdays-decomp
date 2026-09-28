/* Message handler (first rider): a "spawned" message (kind 5) with slot byte 0 starts the
 * +0x3a4 node's first subitem with weight msg[4] << 8; slot 1 starts its second and third
 * subitems at weight 1.0 (all kind 0x17 with the packet's payload bytes). The base handler
 * always runs. */
extern void *Ov107_CreateNodeXformTaskFx24(void *taskList, void *subitem, int mode, int blend, int weight, void *payload);
extern void Ov107_AiState_OnMessage(int actor, unsigned char *msg, int param);

void Ov244_HandleRiderMessageA(int actor, unsigned char *msg, int param)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            (*(void ***)(actor + 0x3a4))[1] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x3a4))[0], 0x17, 0, msg[4] << 8, msg + 5);
            break;
        case 1:
            (*(void ***)(actor + 0x3a4))[3] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x3a4))[2], 0x17, 0, 0x1000, msg + 5);
            (*(void ***)(actor + 0x3a4))[5] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x3a4))[4], 0x17, 0, 0x1000, msg + 5);
            break;
        }
    }
    Ov107_AiState_OnMessage(actor, msg, param);
}
