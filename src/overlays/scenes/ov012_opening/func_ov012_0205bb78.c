/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to TileTextRenderer_Destroy. */
extern void *TileTextRenderer_Destroy();

void *func_ov012_0205bb78() {
    return TileTextRenderer_Destroy();
}
