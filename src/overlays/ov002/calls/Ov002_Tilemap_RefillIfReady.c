/* Refills the tilemap block when the map is in state 3 and has data. */

extern int Ov002_FillTilemapBlock();

void Ov002_Tilemap_RefillIfReady(int arg0) {
    if (*(int *)arg0 != 3) {
        return;
    }
    int p = *(int *)(arg0 + 0x3c);
    if (p == 0) {
        return;
    }
    Ov002_FillTilemapBlock(arg0, p);
}
