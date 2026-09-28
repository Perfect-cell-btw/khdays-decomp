/*
 * Ov002_DrawGaugeColumn - fill one column of the gauge with its style.
 *
 * A style is a pair of nibble values: the cap that closes the column at both
 * ends, and the body that fills the four rows between them. The last two rows
 * are always the same shade, whatever the style.
 *
 * ARM.
 */

typedef unsigned char u8;

typedef struct {
    u8 aStyle[3][2];
} Ov002GaugeStyles;

extern const Ov002GaugeStyles data_ov002_0207e3f4;

extern void Ov002_SetNibble(u8 *pBuffer, int nColumn, int nRow, int nValue);

void Ov002_DrawGaugeColumn(u8 *pBuffer, int nColumn, int nStyle)
{
    Ov002GaugeStyles styles;
    int i;

    styles = data_ov002_0207e3f4;
    Ov002_SetNibble(pBuffer, nColumn, 0, styles.aStyle[nStyle][1]);
    Ov002_SetNibble(pBuffer, nColumn, 5, styles.aStyle[nStyle][1]);

    for (i = 1; i < 5; i++) {
        Ov002_SetNibble(pBuffer, nColumn, i, styles.aStyle[nStyle][0]);
    }
    for (i = 6; i < 8; i++) {
        Ov002_SetNibble(pBuffer, nColumn, i, 3);
    }
}
