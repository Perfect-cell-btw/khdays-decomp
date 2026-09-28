/* ov008 .rodata tables, 0x0208f8e8-0x0208fa10.
 *
 * 8 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov008_0208f8e8: Ov008_LayoutMissionTiles
 *   data_ov008_0208f8f8: Ov008_MissionListDestroy
 *   data_ov008_0208f910: Ov008_InitMissionListRowSurfaces
 *   data_ov008_0208f938: Ov008_InitMissionListRowSurfaces
 *   data_ov008_0208f960: Ov008_InitMissionListRowSurfaces
 *   data_ov008_0208f988: Ov008_InitMissionListRowSurfaces
 *   data_ov008_0208f9b0: Ov008_DrawMissionRow
 *   data_ov008_0208f9e0: Ov008_DrawMissionRow
 */

typedef unsigned char u8;
typedef unsigned short u16;

const int data_ov008_0208f8e8[4] = {
    47, 44, 45, 46,
};

const int data_ov008_0208f8f8[6] = {
    1, 2, 11, 6, 7, 8,
};

const int data_ov008_0208f910[10] = {
    0, 6, 15, 2, 288, 8, 0, 22,
    0, 32,
};

const int data_ov008_0208f938[10] = {
    0, 25, 2, 2, 288, 8, 0, 22,
    0, 32,
};

const int data_ov008_0208f960[10] = {
    0, 22, 5, 2, 288, 8, 0, 22,
    0, 32,
};

const int data_ov008_0208f988[10] = {
    0, 6, 20, 2, 288, 8, 0, 22,
    0, 32,
};

const int data_ov008_0208f9b0[12] = {
    100, 105, 104, 101, 103, 106, 100, 100,
    107, 102, 100, 100,
};

const int data_ov008_0208f9e0[12] = {
    110, 115, 114, 111, 113, 116, 110, 110,
    117, 112, 110, 110,
};
