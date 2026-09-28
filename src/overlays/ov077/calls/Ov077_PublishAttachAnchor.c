extern char *data_ov077_020b9b80;

void Ov077_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov077_020b9b80 + 0x2e50) = *(int *)(obj + 0x263c) + 4;
}
