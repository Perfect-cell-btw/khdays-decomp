/* ov264 .data strings, 0x020cec20-0x020cec40.
 *
 * 3 symbols in one contiguous run. Each array is sized as the original is, so
 * the literal supplies the text and the declared length pads the rest with NUL.
 */

char gOv264PackPathFmt[12] = "Ms/%02x.p";

char gOv264BonePelvisName[12] = "Bone_pelvis";

char gOv264MoveName[8] = "move";
