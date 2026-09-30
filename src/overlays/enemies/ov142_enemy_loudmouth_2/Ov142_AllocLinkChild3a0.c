/* Allocates a sub-object linked to this object (+0x398), installs its initialiser as the state
 * callback and hands it to the shared enemy framework. */

extern int CallocInstance();
extern void func_ov107_020c6624();
extern void Ov142_InitializeSubObject();

int Ov142_AllocLinkChild3a0(int this_) {
    int obj = CallocInstance(0x3a0);
    *(int *)(obj + 0x398) = this_;
    *(int *)(obj + 0x18c) = (int)&Ov142_InitializeSubObject;
    func_ov107_020c6624(obj, 0, (int)&Ov142_InitializeSubObject);
    return obj;
}
