/* Runs callback B of table entry index with three arguments, if set. */

extern char data_02041fdc[];

void Callbacks_RunTableEntryB(int index, int arg1, int arg2, int arg3) {
    void (*callback)(int arg1, int arg2, int arg3);

    callback = *(void (**)(int, int, int))(data_02041fdc + index * 0x18);
    if (callback != 0) {
        callback(arg1, arg2, arg3);
    }
}
