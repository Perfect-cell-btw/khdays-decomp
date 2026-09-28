/*
 * Look up glyph/tile param_1 (as a byte at offset 1 of a scratch key) in table
 * type 0x13 via Ov002_BuildSessionCommand; return 1 if found (result != 0xffff), else 0.
 */
extern int Ov002_BuildSessionCommand(int type, void *key);

int Ov002_GlyphExists(int param_1) {
    int key;
    *((char *)&key + 1) = (char)param_1;

    return Ov002_BuildSessionCommand(0x13, &key) != 0xffff;
}
