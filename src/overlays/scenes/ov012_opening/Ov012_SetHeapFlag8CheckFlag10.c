/* Gets the NNS root heap and ORs bit 8 into the u16 at heap+2; if bit 0x10 is now clear returns 0,
 * else calls Scene_RequestPending(5, 0x190) and returns -2. */

extern int NNSi_FndGetCurrentRootHeap();
extern void Scene_RequestPending();

int Ov012_SetHeapFlag8CheckFlag10(void) {
    unsigned short *p = (unsigned short *)(NNSi_FndGetCurrentRootHeap() + 2);
    unsigned int v = *p | 8;
    *p = v;
    if ((v & 0x10) == 0) return 0;
    Scene_RequestPending(5, 0x190);
    return -2;
}
