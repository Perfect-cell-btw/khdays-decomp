/* MsgQueue_GetHeap = MsgQueue_GetHeap. The 16-byte handler MsgQueue_Init returns as a function
 * pointer: fetches the current root heap (for the subsystem to allocate from) and returns 0. */

extern void Ov025_CopyActiveHitToCursor(void);

int Ov025_MsgQueue_GetHeap(void)
{
    Ov025_CopyActiveHitToCursor();
    return 0;
}
