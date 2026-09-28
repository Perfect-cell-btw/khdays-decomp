/* MsgQueue_GetHeap = MsgQueue_GetHeap. The 16-byte handler MsgQueue_Init returns as a function
 * pointer: fetches the current root heap (for the subsystem to allocate from) and returns 0. */

extern int Ov008_CopyActiveHitToCursor();

int Ov008_MsgQueue_GetHeap(void) {
    Ov008_CopyActiveHitToCursor();
    return 0;
}
