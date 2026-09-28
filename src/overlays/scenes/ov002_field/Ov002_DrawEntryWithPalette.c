/* Draw the entry with its resolved palette: the palette is looked up from the
 * entry's own kind byte and the caller's style byte, then passed to the renderer
 * as a fifth (stacked) argument. */
extern int Ov002_GetModeBlendFrames(void *target, int kind, int style);
extern void Ov002_ApplyAnimMode(void *self, signed char *entry, void *target,
                                int flags, int palette);

void Ov002_DrawEntryWithPalette(unsigned char *self, signed char *entry, void *target,
                         int flags) {
    int palette = Ov002_GetModeBlendFrames(target, *entry, self[3]);

    Ov002_ApplyAnimMode(self, entry, target, flags, palette);
}
