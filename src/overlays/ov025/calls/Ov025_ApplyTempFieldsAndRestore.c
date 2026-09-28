extern void Ov025_Elem_SetPos();
extern void Ov025_TagTracker_InvokeCallback();

void Ov025_ApplyTempFieldsAndRestore(int arg0, int arg1, unsigned short arg2, unsigned short arg3) {
    short v1 = *(short *)(arg1 + 2);
    short v2 = *(short *)(arg1 + 4);
    Ov025_Elem_SetPos(arg0, arg1, arg2, arg3);
    Ov025_TagTracker_InvokeCallback(arg0, arg1);
    Ov025_Elem_SetPos(arg0, arg1, v1, v2);
}
