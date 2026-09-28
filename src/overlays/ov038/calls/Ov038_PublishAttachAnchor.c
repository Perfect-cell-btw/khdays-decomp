/* Publishes the attached block's anchor (+0x263c + 4) into the overlay state. */

extern char *data_ov038_020b4ca0;

void Ov038_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov038_020b4ca0 + 0x2e50) = *(int *)(obj + 0x263c) + 4;
}
