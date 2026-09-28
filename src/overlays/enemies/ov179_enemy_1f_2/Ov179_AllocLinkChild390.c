/* Allocates a sub-object linked to this object (+0x388), installs its initialiser as the state
 * callback and hands it to the shared enemy framework. */

extern int CallocInstance();
extern void func_ov107_020c6624();
extern void Ov179_Construct_2();

int Ov179_AllocLinkChild390(int this_) {
    int obj = CallocInstance(0x390);
    *(int *)(obj + 0x388) = this_;
    *(int *)(obj + 0x18c) = (int)&Ov179_Construct_2;
    func_ov107_020c6624(obj, 0, (int)&Ov179_Construct_2);
    return obj;
}
