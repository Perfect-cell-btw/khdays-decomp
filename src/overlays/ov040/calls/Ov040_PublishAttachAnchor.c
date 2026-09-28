extern char *data_ov040_020b4b20;

void Ov040_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov040_020b4b20 + 0x2d64) = *(int *)(obj + 0x263c) + 4;
}
