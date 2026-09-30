/* main .data pointer tables, 0x020427d4-0x020427f0.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gZhName;
extern int gEnName;
extern int gItName;
extern int gDeName;
extern int gFrName;
extern int gEsName;
extern int gJaName;

void *data_020427d4[7] = {

    &gJaName,

    &gEnName,

    &gFrName,

    &gDeName,

    &gItName,

    &gEsName,

    &gZhName,

};
