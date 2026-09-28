/* Uploads the mission scene's two text layers. */

extern char *data_ov008_02090fa4;
extern void Text_UploadTileBuffer(void *object);

void Ov008_FlushTextLayers(void)
{
    Text_UploadTileBuffer(data_ov008_02090fa4 + 0x976c);
    Text_UploadTileBuffer(data_ov008_02090fa4 + 0x97b8);
}
