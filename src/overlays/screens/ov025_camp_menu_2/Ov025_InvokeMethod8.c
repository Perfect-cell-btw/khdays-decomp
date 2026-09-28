/* Calls the object's method at +8 when the object is initialised (non-zero first word). */

void Ov025_InvokeMethod8(char *obj) {
    if (*(void **)obj) {
        (*(void (**)(void *))(obj + 8))(obj);
    }
}
