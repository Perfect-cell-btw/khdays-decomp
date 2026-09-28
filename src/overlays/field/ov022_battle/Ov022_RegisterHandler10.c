/* Registers the state message handler as network message 0x10. */

extern void StoreGlobalPtrArray4At0c();
extern void Ov022_ApplyStateMessage();
void Ov022_RegisterHandler10(void) { StoreGlobalPtrArray4At0c(0x10, (int)Ov022_ApplyStateMessage); }
