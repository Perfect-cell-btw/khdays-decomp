/* Tail-call Ov009_UpdateWidgetLayer with a third argument of 1. */
extern int Ov009_UpdateWidgetLayer(int a, int b, int c);
int Ov009_CallSelectionHandler(int param_1, int param_2) {
    return Ov009_UpdateWidgetLayer(param_1, param_2, 1);
}
