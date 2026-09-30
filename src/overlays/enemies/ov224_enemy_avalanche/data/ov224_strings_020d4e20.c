/* ov224 .data strings, 0x020d4e20-0x020d4e78.
 *
 * 8 symbols in one contiguous run. Each array is sized as the original is, so
 * the literal supplies the text and the declared length pads the rest with NUL.
 */

char gOv224PackPathFmt[12] = "Ms/%02x.p";

char gOv224BoneHeadName[12] = "Bone_head";

char gOv224BoneTail03Name[16] = "Bone_tail_03";

char gOv224BonePelvisName[12] = "Bone_pelvis";

char gOv224BoneLHandName[12] = "Bone_L_hand";

char gOv224BoneRHandName[12] = "Bone_R_hand";

char gOv224MoveName[8] = "move";

/* rolling sub-item slot handed to each new enemy by the constructor (Ov224_Construct):
 * advances by one per construction and wraps back to 3 at 0x1f; kept word-aligned so the
 * section ends on the counter's word */
struct RollingCounter { unsigned char value; } __attribute__((aligned(4)));
struct RollingCounter data_ov224_020d4e74 = { 3 };
