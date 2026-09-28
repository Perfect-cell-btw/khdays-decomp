/* Message handler of the ov032 enemy (and its byte-identical twins): forwards the message to the
 * +0x2644 item and its +0x30 sub-item, runs the overlay's own handling (46e4) and, on the local
 * player's session only, mirrors the item's +0x18 owner byte into bit 27 of the 64-bit flag
 * word (set for owner 0, cleared otherwise) and into the shared byte at +0x110 of 0204c3d8. */
extern void Ov022_ForwardToNodeHandler(int item, int msg);
extern void Ov052_InvokeBothGroupCallbacks(int obj);
extern void Ov002_Panel_SetOwnerAndRefresh(int owner);
extern int Session_GetLocalPlayerIndex(void);                                                /* Session_GetLocalPlayerIndex */
extern char data_0204c3d8[];

void Ov052_HandleMessage(int obj, int msg)
{
    int owner;

    Ov022_ForwardToNodeHandler(*(int *)(obj + 0x2644), msg);
    Ov022_ForwardToNodeHandler(*(int *)(obj + 0x2644) + 0x30, msg);
    Ov052_InvokeBothGroupCallbacks(obj);
    owner = *(unsigned char *)(*(int *)(obj + 0x2644) + 0x18);
    Ov002_Panel_SetOwnerAndRefresh(owner);
    if (Session_GetLocalPlayerIndex() == 0) {
        if (owner <= 0) {
            *(unsigned long long *)obj |= 0x8000000LL;
        } else {
            *(unsigned long long *)obj &= ~0x8000000LL;
        }
    }
    data_0204c3d8[0x110] = (char)owner;
}
