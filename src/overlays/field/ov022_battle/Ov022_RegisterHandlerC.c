/* Registers the end message handler as network message 0xc. */

extern void StoreGlobalPtrArray4At0c();
extern void Ov022_OnEndMessage();
void Ov022_RegisterHandlerC(void) { StoreGlobalPtrArray4At0c(0xc, (int)Ov022_OnEndMessage); }
