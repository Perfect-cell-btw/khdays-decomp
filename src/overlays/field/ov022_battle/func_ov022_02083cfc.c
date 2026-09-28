/* Instantiates a class (InstantiateClass) and stores the instance in a global. */

extern int InstantiateClass(void *cls, int arg0);
extern int data_ov022_020b28a8;
extern int data_ov022_020b2e60;

void func_ov022_02083cfc(int arg0) {
    *(int *)((char *)&data_ov022_020b2e60 + 4) = InstantiateClass(&data_ov022_020b28a8, arg0);
}
