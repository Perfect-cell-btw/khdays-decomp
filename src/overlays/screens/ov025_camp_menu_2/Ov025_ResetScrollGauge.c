/* Updates the scroll gauge and moves it to the top. */

extern int Ov025_UpdateScrollGauge();
extern int Ov025_SetScrollGaugePos();

void Ov025_ResetScrollGauge(int arg0) {
    Ov025_UpdateScrollGauge(arg0);
    Ov025_SetScrollGaugePos(arg0, 0);
}
