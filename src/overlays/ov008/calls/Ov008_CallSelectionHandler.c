extern void Ov008_UpdateWidgetLayer(void *, void *, int);
void Ov008_CallSelectionHandler(void *arg0, void *arg1)
{
    Ov008_UpdateWidgetLayer(arg0, arg1, 1);
}
