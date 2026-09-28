/* Whether the object state block exists. */

extern int data_ov002_0207fa18;

int Ov002_HasObjectState(void) {
    return *(int *)&data_ov002_0207fa18 != 0;
}
