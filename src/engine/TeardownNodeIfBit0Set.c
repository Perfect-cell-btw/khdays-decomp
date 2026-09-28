/* When an object is flagged as moved, re-inserts it into the quadtree and clears the flag. */

extern void QuadTree_RemoveObject();
extern void QuadTree_InsertObject();

void TeardownNodeIfBit0Set(int this_, int arg1) {
    if ((*(unsigned char *)(arg1 + 0x20) & 1) == 0) return;
    QuadTree_RemoveObject(this_, arg1);
    QuadTree_InsertObject(this_, arg1);
    *(unsigned char *)(arg1 + 0x20) &= ~1;
}
