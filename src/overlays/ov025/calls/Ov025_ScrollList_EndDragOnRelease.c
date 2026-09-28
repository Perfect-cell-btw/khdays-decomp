/* Ends the drag when the touch is released. */

extern int Ov025_GetBlock4a80();
extern int Ov025_GetTouchSample();

void Ov025_ScrollList_EndDragOnRelease(int arg0) {
    int buf[2];
    Ov025_GetTouchSample(Ov025_GetBlock4a80(arg0), (int)buf);
    if (*(unsigned short *)((char *)buf + 4) != 1) {
        *(int *)(arg0 + 0x10) = 0;
    }
}
