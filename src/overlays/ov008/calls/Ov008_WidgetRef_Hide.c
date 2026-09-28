extern int Ov008_GetContext(void);
extern void Ov008_PushSubitemPair(int arg0, int arg1, int arg2);
extern void Ov008_ReleaseTwoSlotsEx(int arg0, int arg1, int arg2);
extern void Ov008_ReleaseTwoSlots(int arg0, int arg1);

void Ov008_WidgetRef_Hide(void *object)
{
    int value = Ov008_GetContext();

    Ov008_PushSubitemPair(value, *(int *)((char *)object + 4), 1);
    Ov008_ReleaseTwoSlotsEx(value, *(int *)((char *)object + 4), 0);
    Ov008_ReleaseTwoSlots(value, *(int *)((char *)object + 4));
}
