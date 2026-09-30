/* Casts a ray (Collision_RunRayCast) with ready-made cast parameters against the collision of the
 * entity manager's model group `index` (8-byte records from +4). EntityMgr_RunRayCast builds the
 * parameters itself. */
extern void *Collision_RunRayCast();
extern int data_0204c208;

void *EntityMgr_RayCastWithParams(int index, int params) {
    return Collision_RunRayCast(data_0204c208 + 4 + index * 8, params);
}
