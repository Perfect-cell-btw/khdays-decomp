/* Tail-call InstantiateClass with the address of data_ov107_020cbaa4. */
extern int InstantiateClass(void *arg);
extern int data_ov107_020cbaa4;
int Ov107_InstantiateFieldClass(void) {
    return InstantiateClass(&data_ov107_020cbaa4);
}
