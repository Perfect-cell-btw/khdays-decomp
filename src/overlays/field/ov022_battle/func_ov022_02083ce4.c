extern int InstantiateClass(void *cls, int arg0);
extern int data_ov022_020b2894;
extern int data_ov022_020b2e60;

void func_ov022_02083ce4(int arg0) {
    *(int *)((char *)&data_ov022_020b2e60 + 4) = InstantiateClass(&data_ov022_020b2894, arg0);
}
