/* Tail-call Ov000_UpdateWidgetLayer with a third argument of 1. */
extern int Ov000_UpdateWidgetLayer(int a, int b, int c);
int Ov000_CallSelectionHandler(int param_1, int param_2) {
    return Ov000_UpdateWidgetLayer(param_1, param_2, 1);
}
