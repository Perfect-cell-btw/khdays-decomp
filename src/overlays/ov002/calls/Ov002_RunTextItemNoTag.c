/* Runs a text item with no tag: streams the item's string with a null first argument. Returns 1
 * like its tagged twin. */

extern int Ov002_StreamFormattedLine();

int Ov002_RunTextItemNoTag(int arg0) {
    Ov002_StreamFormattedLine(0, *(int *)(arg0 + 0x1c));
    return 1;
}
