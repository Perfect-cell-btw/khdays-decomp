/* Ov009_PushCannedDescriptors -- push the four canned descriptors into the screen's work area.
 *
 * The base is data_ov009_020563e4[1] (the screen context pointer), and the four destinations are
 * 0x9680, 0x968c, 0x9698 and 0x96a4 into it -- a stride of 0xc, so they are four consecutive
 * 12-byte slots.
 *
 * mwcc splits each of those offsets differently (0x1680+0x8000 for the first, 0x28c+0x9400 for
 * the rest) because it picks whatever two immediates happen to be encodable; that is automatic
 * and nothing in the source controls it. */

extern void Resource_BindByName(int dst, const void *src);
extern int data_ov009_020563e4[];
extern int gOv009TextFontEu08Path;
extern int gOv009TextFontEu10Path;
extern int gOv009TextFontEu08SPath;
extern int gOv009TextFontEu10SPath;

void Ov009_PushCannedDescriptors(void) {
    Resource_BindByName(data_ov009_020563e4[1] + 0x9680, &gOv009TextFontEu08Path);
    Resource_BindByName(data_ov009_020563e4[1] + 0x968c, &gOv009TextFontEu10Path);
    Resource_BindByName(data_ov009_020563e4[1] + 0x9698, &gOv009TextFontEu08SPath);
    Resource_BindByName(data_ov009_020563e4[1] + 0x96a4, &gOv009TextFontEu10SPath);
}
