/* Casts a ray 5 units down from just above the entry's position; stores the hit point (or the
 * position) in out. Returns 1 on a hit. */

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

typedef struct Entry {
    char pad_0000[8];
    VecFx32 pos;
} Entry;

typedef struct Hit {
    char pad_0000[0xc];
    int distance0c;
} Hit;

extern Entry *CollModel_FindEntry(void *cont);
extern Hit *Collision_CastRay(void *world, VecFx32 *from, VecFx32 *dir);
extern void Vec3ScaleAddQ27(int s, const VecFx32 *dir, const VecFx32 *from, VecFx32 *out);

int Collision_ProbeGround(void *cont, int p3, void *out) {
    Entry *entry = CollModel_FindEntry(cont);
    VecFx32 from;
    VecFx32 dir;
    Hit *hit;

    from.x = entry->pos.x;
    from.y = entry->pos.y + 0x1000;
    from.z = entry->pos.z;
    dir.x = 0;
    dir.y = -0x5000;
    dir.z = 0;

    hit = Collision_CastRay(cont, &from, &dir);
    if (hit != 0) {
        Vec3ScaleAddQ27(hit->distance0c, &dir, &from, (VecFx32 *)out);
        return 1;
    }
    *(VecFx32 *)out = entry->pos;
    return 0;
}
