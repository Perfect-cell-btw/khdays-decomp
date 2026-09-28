extern void Ov025_BuildActionPage();
extern void PlaySound();

void Ov025_SetField20AndDispatch(int arg0, int arg1, int arg2, int arg3) {
    *(int *)(arg0 + 0x20) = arg1;
    if (*(int *)(arg0 + 0xa4) == 1)
        Ov025_BuildActionPage(arg0, 2, arg2, arg3);
    else
        Ov025_BuildActionPage(arg0, 5, arg2, arg3);
    PlaySound(0, 1);
}
