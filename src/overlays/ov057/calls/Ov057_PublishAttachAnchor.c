/* Publishes the attached block's anchor (+0x263c + 4) into the overlay state. */

extern char *data_ov057_020b74a0;

void Ov057_PublishAttachAnchor(char *obj) {
    *(int *)(data_ov057_020b74a0 + 0x2e50) = *(int *)(obj + 0x263c) + 4;
}
