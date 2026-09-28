extern int GameState_GetField(int nId, int nSlot);
extern int Ov002_Hud_IsPanelOpen(void);

typedef int (*Ov002NodeHandler)(int pNode, int pEvent);

/* Forward the event to the node's secondary handler, when the node is live,
 * the handler exists and the gate is clear. Returns the handler's result, or 0.
 * The handler is read twice because the gate call sits between the null test
 * and the dispatch. */
int Ov002_DispatchNodeEventGated(int pNode, int pEvent)
{
    int bLive;

    bLive = (GameState_GetField(*(unsigned short *)(pNode + 0x14),
                           *(unsigned char *)(pNode + 0x16)) & 1) != 0;
    if (bLive) {
        if (*(Ov002NodeHandler *)(*(int *)(pNode + 8) + 0x20) != 0) {
            if (Ov002_Hud_IsPanelOpen() == 0) {
                return (*(Ov002NodeHandler *)(*(int *)(pNode + 8) + 0x20))(pNode, pEvent);
            }
        }
    }

    return 0;
}
