/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to TileTextRenderer_Destroy. */
extern void *TileTextRenderer_Destroy();

void *func_ov024_020835cc() {
    return TileTextRenderer_Destroy();
}
