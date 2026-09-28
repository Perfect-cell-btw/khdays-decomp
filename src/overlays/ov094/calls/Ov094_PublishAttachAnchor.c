extern char *data_ov094_020bc240;

void Ov094_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov094_020bc240 + 0x2e50) = *(int *)(obj + 0x263c) + 4;
}
