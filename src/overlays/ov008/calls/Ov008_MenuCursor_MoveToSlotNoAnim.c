extern void Ov008_MenuCursor_MoveToSlot(void *, void *, int);
void Ov008_MenuCursor_MoveToSlotNoAnim(void *arg0, void *arg1)
{
    Ov008_MenuCursor_MoveToSlot(arg0, arg1, 0);
}
