/* Streams the item's formatted line (+0x1c) to the text output; returns 1. */

extern int Ov002_StreamFormattedLine();
extern int data_ov002_0207f03c;

int Ov002_RunTextItemTagged(int arg0) {
    Ov002_StreamFormattedLine(&data_ov002_0207f03c, *(int *)(arg0 + 0x1c));
    return 1;
}
