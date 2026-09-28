extern void Ov107_AiState_PostTickBase(void *obj);
struct blk11 { int w[11]; };
void Ov251_PropagateBlockChainThenNotify(char *obj) {
    *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x39c) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x388)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x38c) + 0x10);
    Ov107_AiState_PostTickBase(obj);
}
