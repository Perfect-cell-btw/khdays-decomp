/* Menu entry widget 8 callback: handles the cancel flags. */

extern void *data_ov008_02090f1c;
extern void Ov008_HandleCancelFlags(void *);
void Ov008_MenuEntry_Cancel(void)
{
    Ov008_HandleCancelFlags(data_ov008_02090f1c);
}
