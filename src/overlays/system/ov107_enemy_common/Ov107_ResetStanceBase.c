/* Actor +0x1f8 handler: clears the pending action, sets stance bits 0x82, clears bit 0 and resets
 * +0x2e8 to 0x800. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj88fc {
    char pad000[0x60];
    u16 hw60;
    char pad062[0x1c7 - 0x62];
    u8 field_1c7;
    char pad1c8[0x2e8 - 0x1c8];
    u32 field_2e8;
} Obj88fc;

void Ov107_ResetStanceBase(Obj88fc *self)
{
    u16 hw;

    self->field_1c7 = 0;

    hw = self->hw60;
    self->hw60 = (hw & ~0xff00) |
        (((((u32)hw << 0x10) >> 0x18) | 0x82) << 0x18 >> 0x10);

    hw = self->hw60;
    self->hw60 = (hw & ~0xff00) |
        (((u32)(u16)((((u32)hw << 0x10) >> 0x18) & ~1) << 0x18) >> 0x10);

    self->field_2e8 = 0x800;
}
