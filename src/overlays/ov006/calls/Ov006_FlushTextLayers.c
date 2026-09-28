/* Ov006_FlushTextLayers -- hide/flush the two Mission Mode-screen BG text layers (ctx+0x976c, +0x97b8). */
extern void Text_UploadTileBuffer(int layer);
extern int  data_ov006_02056664;   /* -> Mission Mode-screen context */

void Ov006_FlushTextLayers(void) {
    Text_UploadTileBuffer(data_ov006_02056664 + 0x976c);
    Text_UploadTileBuffer(data_ov006_02056664 + 0x97b8);
}
