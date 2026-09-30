/* ov096 constructor argument block data_ov096_020bbfe4, 0x020bbfe4-0x020bbff8 (.rodata).
 *
 * Five words handed to a class constructor: the resource path of the object's archive
 * ('ba/ch/ma/li_e2.p.z') and four parameters the constructor reads.  Used by Ov096_SetupSequenceSlots.
 */

typedef struct ClassCtorArgs {
    const char *pszResource;  /* 0x00 */
    int aParam[4];            /* 0x04 */
} ClassCtorArgs;

extern char gOv096MarluxiaLiE2PackPath;  /* the path string */

const ClassCtorArgs data_ov096_020bbfe4 = {
    &gOv096MarluxiaLiE2PackPath,
    { 1, 0, 0, 0 },
};
