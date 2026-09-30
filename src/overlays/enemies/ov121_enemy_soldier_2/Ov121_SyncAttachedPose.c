/* Republishes the attached pose.
 *
 * ov121 pose sync: drop the pending node-slot task (unless the actor is in
 * action state 6) and republish the Bip01 bone transform into both pose
 * handles, then let the ov107 actor base finish the frame.
 *
 * The bone record is the 0x30-byte entry InsertSortedEntryWithKey allocates per bone
 * name; its +0x04 block is 44 bytes wide and is copied wholesale, which is
 * why mwcc emits the ldm/stm 4+4+3 sequence rather than field stores.
 *
 * CODEGEN NOTE -- the copy must be written as a struct-FIELD assignment
 * between typed pointers.  With raw `*(T *)(addr)` casts mwcc swaps the roles
 * of ip and lr (ip walks the source instead of the destination); giving each
 * side a real struct type with the block as a named field pins ip to the
 * destination the way the ROM has it. */
struct Ov121BoneXform {
    int w[11];
};

struct Ov121PoseNode {
    char pad00[0x10];
    struct Ov121BoneXform xform;
};

struct Ov121BoneRec {
    int tag;
    struct Ov121BoneXform xform;
};

extern void TaskList_FinishByTag();
extern void Ov107_AiState_PostTickBase();

void Ov121_SyncAttachedPose(int self)
{
    if (*(signed char *)(self + 0x1c6) != 6 &&
        *(int *)(*(int *)(self + 0x3a4) + 0xc) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c),
                      *(int *)(*(int *)(self + 0x3a4) + 0xc));
        *(int *)(*(int *)(self + 0x3a4) + 0xc) = 0;
    }

    (**(struct Ov121PoseNode ***)(self + 0x388))->xform =
        (*(struct Ov121BoneRec **)(self + 0x39c))->xform;

    (*(struct Ov121PoseNode **)(self + 0x38c))->xform =
        (*(struct Ov121BoneRec **)(self + 0x39c))->xform;

    Ov107_AiState_PostTickBase(self);
}
