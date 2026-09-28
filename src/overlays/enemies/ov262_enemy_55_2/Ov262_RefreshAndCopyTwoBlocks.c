extern void Ov107_AiState_DispatchModelCallbacks(void *obj);
struct blk11 { int w[11]; };
void Ov262_RefreshAndCopyTwoBlocks(char *obj) {
    Ov107_AiState_DispatchModelCallbacks(obj);
    *(struct blk11 *)(*(char **)(obj + 0x388) + 0x30) = *(struct blk11 *)(*(char **)(obj + 0x390) + 4);
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x30) = *(struct blk11 *)(*(char **)(obj + 0x394) + 4);
}
