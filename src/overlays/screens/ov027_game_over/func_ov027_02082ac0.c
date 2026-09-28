/* Instantiates a class (InstantiateClass) and stores the instance in a global. */

extern int InstantiateClass(void *cls, int arg0);
extern int data_ov027_02083ef8;
extern int data_ov027_02083ee0;

void func_ov027_02082ac0(int arg0) {
    *(int *)((char *)&data_ov027_02083ee0 + 4) = InstantiateClass(&data_ov027_02083ef8, arg0);
}
