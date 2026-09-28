extern void Ov002_Field_SetSpawnPos(int arg);
extern char *data_ov002_0207fa00;
/* Only in link mode 1, and only for event kind 1, forward the payload. */
void Ov002_ForwardLinkEventKind1(int kind, int arg) {
    if (*(unsigned char *)((int)data_ov002_0207fa00 + 0x8d0b) != 1) {
        return;
    }
    if (kind == 0) {
        return;
    }
    if (kind != 1) {
        return;
    }
    Ov002_Field_SetSpawnPos(arg);
}
