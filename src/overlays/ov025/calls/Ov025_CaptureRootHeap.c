extern int NNSi_FndGetCurrentRootHeap();
extern int data_ov025_020b5754;
extern int Ov025_MsgQueue_GetHeap();

int Ov025_CaptureRootHeap(int arg0) {
    data_ov025_020b5754 = NNSi_FndGetCurrentRootHeap(arg0);
    return (int)Ov025_MsgQueue_GetHeap;
}
