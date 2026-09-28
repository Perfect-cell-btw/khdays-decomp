/* Captures the current root heap and returns the heap getter step. */

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void *data_ov002_0207f610;
extern void Ov002_MsgQueue_GetHeap(void);

void (*Ov002_CaptureRootHeap(void))(void)
{
    data_ov002_0207f610 = NNSi_FndGetCurrentRootHeap();
    return Ov002_MsgQueue_GetHeap;
}
