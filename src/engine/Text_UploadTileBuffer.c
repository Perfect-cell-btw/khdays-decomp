/* Enqueues the upload of a text surface's tile buffer (rows times row size bytes) to its VRAM
 * destination. */

extern int GFXi_EnqueueCommand(void *a, int b, int c, int d);

typedef struct {
    char _pad[0x2c];
    int  f2c;            /* +0x2c */
    void *f30;           /* +0x30 */
    int  f34;            /* +0x34 */
    unsigned short f38;  /* +0x38 */
    char _pad2[4];
    unsigned char f3e;   /* +0x3e */
} S;

int Text_UploadTileBuffer(S *p) {
    return GFXi_EnqueueCommand(p->f30, p->f3e * p->f38, p->f2c, p->f34);
}
