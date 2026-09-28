/* Bind each of this enemy's eight 0x170-byte parts to the shared rig, by handing the
 * rig handle and the part's 0x108 bone block to the binder. Same family as
 * Ov035_BindRig / Ov039_BindRig, with two differences: the parts are
 * embedded in the object (at +0x234) instead of hanging off a pointer array, and the
 * rig block is reached through the owner pointer at +0xdb4 rather than through self.
 *
 * The rig-block base has to be written INSIDE the loop and left for the compiler to
 * hoist. Computing it into a local before the loop is semantically identical but
 * emits it ahead of the counter init, where the original has it after -- the hoisted
 * copy lands at the END of the preheader, which is exactly where the original's is. */
extern void func_ov022_020b15a4(int handle, void *bones);

void Ov099_BindPartRigs(int self)
{
    int owner = *(int *)(self + 0xdb4);
    int i;
    char *part = (char *)(self + 0x234);

    for (i = 0; i < 8; i++, part += 0x170) {
        func_ov022_020b15a4(((int *)(owner + 0x2000))[0x18f], part + 0x108);
    }
}
