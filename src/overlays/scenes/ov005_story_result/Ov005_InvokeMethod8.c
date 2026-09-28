void Ov005_InvokeMethod8(char *obj) {
    if (*(void **)obj) {
        (*(void (**)(void *))(obj + 8))(obj);
    }
}
