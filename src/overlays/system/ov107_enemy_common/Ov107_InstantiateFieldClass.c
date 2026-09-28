/* Tail-call InstantiateClass with the address of data_ov107_020cbaa4. */
extern int InstantiateClass(void *arg, int arg2);
extern int data_ov107_020cbaa4;
int Ov107_InstantiateFieldClass(int arg0, int arg1) {
    return InstantiateClass(&data_ov107_020cbaa4, arg1);
}
