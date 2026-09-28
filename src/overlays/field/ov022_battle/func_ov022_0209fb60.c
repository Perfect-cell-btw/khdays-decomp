/* Binds the resources of one of the actor's attached parts. */

extern void Ov002_BindActorResources(int a0, int a1, int a2, int a3, int a4, int a5);

void func_ov022_0209fb60(int arg0, int arg1, int arg2, int arg3) {
    Ov002_BindActorResources(arg0 + 0xda8 + arg1 * 0x164,
                        *(int *)(arg0 + 0x2bd0),
                        *(unsigned char *)(arg0 + 9),
                        *(int *)(arg0 + 0xc),
                        *(unsigned char *)(arg0 + 0x918),
                        arg2);
}
