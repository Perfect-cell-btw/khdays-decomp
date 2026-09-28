/* Clears the mission scene's two text layers. */

extern char *data_ov008_02090fa4;
extern void CallVirtSlot1(void *object, int arg1);

void Ov008_ResetTextLayers(void)
{
    CallVirtSlot1(data_ov008_02090fa4 + 0x976c, 0);
    CallVirtSlot1(data_ov008_02090fa4 + 0x97b8, 0);
}
