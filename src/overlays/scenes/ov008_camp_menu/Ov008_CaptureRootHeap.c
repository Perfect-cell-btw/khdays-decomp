/* Captures the current root heap and returns the heap getter step. */

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void *data_ov008_02090f14;
extern void Ov008_MsgQueue_GetHeap(void);

void (*Ov008_CaptureRootHeap(void))(void)
{
    data_ov008_02090f14 = NNSi_FndGetCurrentRootHeap();
    return Ov008_MsgQueue_GetHeap;
}
