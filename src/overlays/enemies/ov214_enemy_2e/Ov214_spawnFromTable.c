/* Spawns the projectile for the current animation state: picks its texture from the overlay's
 * table, initialises the child projectile model and refreshes its callbacks. */

struct nine { int w[9]; };
struct b1 { unsigned char b : 1; };
extern int Ov107_PackTextureHandle(void *this, int v);
extern void Ov214_initChildProjectile(void *a, int b, int c, void *d);
extern void RefreshObjectCallbacks(void *a, int b);
extern int data_ov214_020cebf8[];

void Ov214_spawnFromTable(char *this) {
    int buf[9];
    int v;
    *(struct nine *)buf = *(struct nine *)data_ov214_020cebf8;
    v = Ov107_PackTextureHandle(this, buf[*(signed char *)(this + 0x310)]);
    Ov214_initChildProjectile(*(void **)(this + 0x384), v,
                        ((struct b1 *)(this + 0x311))->b, this + 0x388);
    RefreshObjectCallbacks(*(void **)(this + 0x384), 0);
}
