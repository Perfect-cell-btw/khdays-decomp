extern void Ov107_AiState_PostTickBase(void *obj);
struct blk11 { int w[11]; };
void Ov146_PropagateBlockChainThenNotify(char *obj) {
    *(struct blk11 *)(*(char **)(obj + 0x3b0) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3c0) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3ac)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3b0) + 0x10);
    Ov107_AiState_PostTickBase(obj);
}
