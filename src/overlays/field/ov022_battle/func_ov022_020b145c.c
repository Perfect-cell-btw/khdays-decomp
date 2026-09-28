/* Creates the battle helper instance when it is not set up. */

extern int InstantiateClass(void *cls, int arg0);
extern int data_ov022_020b2eb8;
extern int data_ov022_020b2db0;

void func_ov022_020b145c(void) {
    if (((int *)&data_ov022_020b2eb8)[0] == 0 && ((int *)&data_ov022_020b2eb8)[1] == 0) {
        ((int *)&data_ov022_020b2eb8)[1] = InstantiateClass(&data_ov022_020b2db0, 0);
    }
}
