/* Streams the item's formatted line (+0x1c) to the text output; returns 1. */

extern int Ov002_StreamFormattedLine();
extern int gOv002SName_2;

int Ov002_RunTextItemTagged(int arg0) {
    Ov002_StreamFormattedLine(&gOv002SName_2, *(int *)(arg0 + 0x1c));
    return 1;
}
