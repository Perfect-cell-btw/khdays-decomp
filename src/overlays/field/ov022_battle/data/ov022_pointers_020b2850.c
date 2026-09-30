/* ov022 .rodata pointer tables, 0x020b2850-0x020b2874.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gOv022DummyName;
extern int gOv022RgPZName;
extern int gOv022ItPZName;
extern int gOv022GlPZName;
extern int gOv022AsPZName;
extern int gOv022Ma0PZName;
extern int gOv022Ma2PZName;
extern int gOv022Ma1PZName;

void *const data_ov022_020b2850[9] = {

    &gOv022DummyName,

    &gOv022GlPZName,

    &gOv022RgPZName,

    &gOv022AsPZName,

    &gOv022Ma2PZName,

    &gOv022ItPZName,

    &gOv022Ma0PZName,

    &gOv022Ma1PZName,

    &gOv022Ma2PZName,

};
