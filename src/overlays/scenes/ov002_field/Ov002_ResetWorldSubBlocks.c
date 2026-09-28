/* Resets both of the world object's sub-blocks and arms it. */

extern int data_ov002_0207fa00;
extern int Obj_ResetBothSubBlocksAndArm();

int Ov002_ResetWorldSubBlocks(void) {
    return Obj_ResetBothSubBlocksAndArm(*(int *)&data_ov002_0207fa00 + 8);
}
