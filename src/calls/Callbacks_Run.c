extern void (*data_0204bd88[])(void *ptr);
extern void *data_0204bd94[];

void Callbacks_Run(int index) {
    void (*callback)(void *ptr) = data_0204bd88[index];

    if (callback != 0) {
        callback(data_0204bd94[index]);
    }
}
