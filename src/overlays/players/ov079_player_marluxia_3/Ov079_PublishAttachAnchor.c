/* Publishes the attached block's anchor (+0x263c + 4) into the overlay state. */

extern char *data_ov079_020b9a00;

void Ov079_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov079_020b9a00 + 0x2d64) = *(int *)(obj + 0x263c) + 4;
}
