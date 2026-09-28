extern int StoreGlobalPtrArray4At0c();
extern int Ov002_DispatchSessionPacket();

int Ov002_Link_InstallPacketHandler(void) {
    return StoreGlobalPtrArray4At0c(7, Ov002_DispatchSessionPacket);
}
