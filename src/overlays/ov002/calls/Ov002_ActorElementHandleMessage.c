extern int Ov002_IsSessionOpen(void);
extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int nIndex);
extern int Ov002_GetSlotTableByte(int nHandle);
extern void Slot_Spawn(int a, int b, void *pBlock, int d);

/* Act on a message delivered to an element.
 *
 * Message 1 just moves the element's phase on. Message 2 only does anything for
 * the local player, and only when the message names that player's own slot; it
 * then starts effect 0x5e on the element's block.
 */
void Ov002_ActorElementHandleMessage(char *pElement, unsigned char *pMsg)
{
    switch (pMsg[0]) {
    case 1:
        *(unsigned char *)(pElement + 0x1b6) = 2;
        break;

    case 2:
        if (Ov002_IsSessionOpen() == 0) {
            return;
        }
        if (*(short *)(pMsg + 4)
            != Ov002_GetSlotTableByte(Ov022_GetEntryField66(QueryActiveStateOrDelegate()))) {
            return;
        }
        Slot_Spawn(0, 0x5e, pElement + 0xe0, 0);
        break;
    }
}
