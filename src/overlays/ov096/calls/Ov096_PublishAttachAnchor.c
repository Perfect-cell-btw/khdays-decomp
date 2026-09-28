extern char *data_ov096_020bc0c0;

void Ov096_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov096_020bc0c0 + 0x2d64) = *(int *)(obj + 0x263c) + 4;
}
