/* Tail-call Ov008_UpdateWidgetLayer with a zero third argument. */

extern void Ov008_UpdateWidgetLayer(void *, void *, int);
void Ov008_UpdateWidgetLayerDefault(void *arg0, void *arg1)
{
    Ov008_UpdateWidgetLayer(arg0, arg1, 0);
}
