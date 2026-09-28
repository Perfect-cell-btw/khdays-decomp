/* Publishes the attached block's anchor (+0x263c + 4) into the overlay state. */

extern char *data_ov059_020b7320;

void Ov059_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov059_020b7320 + 0x2d64) = *(int *)(obj + 0x263c) + 4;
}
