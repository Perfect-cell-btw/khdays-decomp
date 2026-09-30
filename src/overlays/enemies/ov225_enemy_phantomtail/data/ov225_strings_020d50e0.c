/* ov225 .data strings, 0x020d50e0-0x020d5138.
 *
 * 8 symbols in one contiguous run. Each array is sized as the original is, so
 * the literal supplies the text and the declared length pads the rest with NUL.
 */

char gOv225PackPathFmt[12] = "Ms/%02x.p";

char gOv225BoneHeadName[12] = "Bone_head";

char gOv225BoneTail03Name[16] = "Bone_tail_03";

char gOv225BonePelvisName[12] = "Bone_pelvis";

char gOv225BoneLHandName[12] = "Bone_L_hand";

char gOv225BoneRHandName[12] = "Bone_R_hand";

char gOv225MoveName[8] = "move";

/* rolling sub-item slot handed to each new enemy by the constructor (Ov225_Construct):
 * advances by one per construction and wraps back to 3 at 0x1f; kept word-aligned so the
 * section ends on the counter's word */
struct RollingCounter { unsigned char value; } __attribute__((aligned(4)));
struct RollingCounter data_ov225_020d5134 = { 3 };
