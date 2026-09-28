extern void GameState_SetFlag(void *obj);
extern void func_020235bc(void *obj);
extern int data_ov069_020baa2c;

void Ov069_DispatchTableEntry(void *obj, int index, int arg3) {
    int (*fn)(int) = ((int (**)(int)) &data_ov069_020baa2c)[index];
    if (fn) {
        if (fn(arg3)) {
            GameState_SetFlag(obj);
        } else {
            func_020235bc(obj);
        }
    }
}
