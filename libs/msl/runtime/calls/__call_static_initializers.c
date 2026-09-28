typedef void (*func_02020808_cb)(void);

extern func_02020808_cb ARM9_CTOR_START[];

void __call_static_initializers(void) {
    func_02020808_cb *callbacks = ARM9_CTOR_START;

    while (callbacks != 0 && *callbacks != 0) {
        (*callbacks)();
        callbacks++;
    }
}
