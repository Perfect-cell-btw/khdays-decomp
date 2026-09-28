/* Ov008_PushCannedDescriptors -- push the four canned descriptors into the screen's work area.
 *
 * The base is data_ov008_02090f04[1] (the screen context pointer), and the four destinations are
 * 0x9680, 0x968c, 0x9698 and 0x96a4 into it -- a stride of 0xc, so they are four consecutive
 * 12-byte slots.
 *
 * mwcc splits each of those offsets differently (0x1680+0x8000 for the first, 0x28c+0x9400 for
 * the rest) because it picks whatever two immediates happen to be encodable; that is automatic
 * and nothing in the source controls it. */

extern void Resource_BindByName(int dst, const void *src);
extern int data_ov008_02090f04[];
extern int data_ov008_0208ffc4;
extern int data_ov008_0208ffdc;
extern int data_ov008_0208fff4;
extern int data_ov008_0209000c;

void Ov008_PushCannedDescriptors(void) {
    Resource_BindByName(data_ov008_02090f04[1] + 0x9680, &data_ov008_0208ffc4);
    Resource_BindByName(data_ov008_02090f04[1] + 0x968c, &data_ov008_0208ffdc);
    Resource_BindByName(data_ov008_02090f04[1] + 0x9698, &data_ov008_0208fff4);
    Resource_BindByName(data_ov008_02090f04[1] + 0x96a4, &data_ov008_0209000c);
}
