/* Updates the scroll gauge and moves it to the top. */

extern void Ov008_UpdateScrollGauge(void *);
extern void Ov008_SetScrollGaugePos(void *, int);
void Ov008_ResetScrollGauge(void *obj)
{
    Ov008_UpdateScrollGauge(obj);
    Ov008_SetScrollGaugePos(obj, 0);
}
