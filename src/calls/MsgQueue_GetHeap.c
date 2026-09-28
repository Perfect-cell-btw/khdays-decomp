/* MsgQueue_GetHeap = MsgQueue_GetHeap. The 16-byte handler MsgQueue_Init returns as a
 * function pointer: fetches the current root heap (for the subsystem to allocate from)
 * and returns 0. */
extern void *NNSi_FndGetCurrentRootHeap(void);

int MsgQueue_GetHeap(void)
{
    NNSi_FndGetCurrentRootHeap();
    return 0;
}
