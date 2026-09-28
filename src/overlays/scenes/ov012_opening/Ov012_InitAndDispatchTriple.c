/* Script command: starts the opening movie player, drains its stream to the given point and uploads
 * its text. */

extern int ByteCode_ResolveOperand(void *a, unsigned short *param_2);
extern void Ov012_ArmAndStart(int x);
extern void Ov012_MobiClip_DrainStream(int x, int y);
extern void Ov012_ReleaseField50IfSet(int x);

int Ov012_InitAndDispatchTriple(char *arg1, unsigned short *param_2) {
    int v = ByteCode_ResolveOperand(arg1, param_2);
    Ov012_ArmAndStart(*(int *)(*(int *)(arg1 + 0x128) + 0xc));
    Ov012_MobiClip_DrainStream(*(int *)(*(int *)(arg1 + 0x128) + 0xc), v);
    Ov012_ReleaseField50IfSet(*(int *)(*(int *)(arg1 + 0x128) + 0xc));
    return 1;
}
