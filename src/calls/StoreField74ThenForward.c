extern int ModelInst_Init();

int StoreField74ThenForward(int arg0, int arg1, int arg2) {
    *(int *)(arg0 + 0x74) = arg1;
    return ModelInst_Init(arg0, arg2, 1);
}
