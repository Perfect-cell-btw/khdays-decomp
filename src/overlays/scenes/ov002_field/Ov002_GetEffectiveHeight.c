/* Work out the object's effective height: its base height plus the signed
 * adjustment at +4, plus the extra row the wide-layout flag asks for. Capped at
 * 0x78 and floored at 1 -- nothing may end up with no height at all. */
extern int Ov002_GetRootField8bae(void *self);

typedef struct {
    unsigned char bFlags;       /* +0 */
} Ov002LayoutFlags;

typedef struct {
    char pad0000[8];
    unsigned char bExtraRow;    /* +8 */
} Ov002LayoutMetrics;

extern Ov002LayoutFlags data_0204c240;
extern Ov002LayoutMetrics data_0204c254;

int Ov002_GetEffectiveHeight(char *self) {
    int height = Ov002_GetRootField8bae(self) + *(signed char *)(self + 4);

    if ((data_0204c240.bFlags & 2) != 0) {
        height += data_0204c254.bExtraRow;
    }

    if (height > 0x78) {
        height = 0x78;
    }

    if (height > 0) {
        return height;
    }

    return 1;
}
