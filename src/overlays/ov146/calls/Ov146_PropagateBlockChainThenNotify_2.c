extern void Ov107_AiState_PostTickBase(void *obj);
struct blk11 { int w[11]; };
void Ov146_PropagateBlockChainThenNotify_2(char *obj) {
    *(struct blk11 *)(*(char **)(obj + 0x3b0) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3b8) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3ac)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3b0) + 0x10);
    Ov107_AiState_PostTickBase(obj);
}
