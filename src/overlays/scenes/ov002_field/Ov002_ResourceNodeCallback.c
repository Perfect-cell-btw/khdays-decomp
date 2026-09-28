/* Resource callback: draws the entry's sprite quad. */

extern int Ov002_DrawSpriteQuad();

int Ov002_ResourceNodeCallback(int arg0) {
    return Ov002_DrawSpriteQuad(arg0, 0);
}
