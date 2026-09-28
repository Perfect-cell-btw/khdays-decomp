/* Tail-call Ov025_UpdateWidgetLayer with a third argument of 1. */

extern int Ov025_UpdateWidgetLayer();

int Ov025_CallSelectionHandler(int arg0, int arg1) {
    return Ov025_UpdateWidgetLayer(arg0, arg1, 1);
}
