/* Installs the joint matrix capture callback and sets the capture mode to 3. */

extern void Obj_CaptureSelectedJointMtx(void);
void func_ov022_0209a4e0(int arg0) {
    *(void (**)(void))(arg0 + 0x24) = Obj_CaptureSelectedJointMtx;
    *(char *)(arg0 + 0x92) = 3;
}
