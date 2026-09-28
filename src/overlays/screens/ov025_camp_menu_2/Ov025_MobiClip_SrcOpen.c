/* Creates the MobiClip source instance with the argument. */

extern int InstantiateClass();
extern int data_ov025_020b49c4;
extern int data_ov025_020b49c0;

void Ov025_MobiClip_SrcOpen(int arg0) {
    data_ov025_020b49c0 = InstantiateClass(&data_ov025_020b49c4, arg0);
}
