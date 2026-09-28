/* Stores a tile text renderer's ready flag. */

void Ov024_TileTextRenderer_SetReady(char *self, int value) { *(int *)(self + 0x70) = value; }
