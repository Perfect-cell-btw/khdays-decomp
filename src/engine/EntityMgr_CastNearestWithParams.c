/* Runs Collision_CastNearest with ready-made cast parameters against the collision of the entity
 * manager's model group `index` (8-byte records from +4). */
extern void *Collision_CastNearest();
extern int data_0204c208;

void *EntityMgr_CastNearestWithParams(int index, int params) {
    return Collision_CastNearest(data_0204c208 + 4 + index * 8, params);
}
