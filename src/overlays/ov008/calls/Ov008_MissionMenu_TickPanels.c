extern void Ov008_DragInfoPanel(void *object, int arg1);
extern void Ov008_TickSlider(void *object);

void Ov008_MissionMenu_TickPanels(void *object)
{
    int value = *(int *)((char *)object + 0x158);

    if (value != 0) {
        Ov008_DragInfoPanel(object, value);
    }

    if (*(int *)((char *)object + 8) != 0) {
        Ov008_TickSlider(object);
    }
}
