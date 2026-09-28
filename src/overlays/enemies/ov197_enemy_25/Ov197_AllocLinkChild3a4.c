/* Allocates a sub-actor linked to this object (+0x390), installs its initialiser as the state
 * callback and hands it to the shared enemy framework. */

extern int CallocInstance();
extern void func_ov107_020c6624();
extern void Ov197_InitSubActor();

int Ov197_AllocLinkChild3a4(int this_) {
    int obj = CallocInstance(0x3a4);
    *(int *)(obj + 0x390) = this_;
    *(int *)(obj + 0x18c) = (int)&Ov197_InitSubActor;
    func_ov107_020c6624(obj, 0, (int)&Ov197_InitSubActor);
    return obj;
}
