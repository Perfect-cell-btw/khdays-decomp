extern void *NNSi_FndGetCurrentRootHeap(void);
extern void *data_ov009_020563f4;
extern void Ov009_MsgQueue_GetHeap(void);

void (*Ov009_CaptureRootHeap(void))(void)
{
    data_ov009_020563f4 = NNSi_FndGetCurrentRootHeap();
    return Ov009_MsgQueue_GetHeap;
}
