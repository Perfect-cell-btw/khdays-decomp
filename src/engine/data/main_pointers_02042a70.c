/* main .data pointer tables, 0x02042a70-0x02042ac0.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gDoName;
extern int gLuName;
extern int gMaName;
extern int gLeName;
extern int gDeName_2;
extern int gR2Name;
extern int gXaName;
extern int gVeName;
extern int gXeName;
extern int gXoName;
extern int gZeName;
extern int gMiName;
extern int gRoName;
extern int gRiName;
extern int gGoName;
extern int gAxName;
extern int gXiName;
extern int gLaName;
extern int gSaName;
extern int gSoName;

void *data_02042a70[20] = {

    &gRoName,

    &gAxName,

    &gXiName,

    &gSaName,

    &gXaName,

    &gSoName,

    &gDeName_2,

    &gLaName,

    &gLeName,

    &gLuName,

    &gMaName,

    &gRiName,

    &gVeName,

    &gXeName,

    &gXoName,

    &gZeName,

    &gMiName,

    &gDoName,

    &gGoName,

    &gR2Name,

};
