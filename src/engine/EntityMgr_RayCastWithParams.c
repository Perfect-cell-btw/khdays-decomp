/* Casts a ray (Collision_RunRayCast) with ready-made cast parameters against the collision of the
 * entity manager's model group `index` (8-byte records from +4). EntityMgr_RunRayCast builds the
 * parameters itself. */
extern void *Collision_RunRayCast();
extern int gEntityMgr;

void *EntityMgr_RayCastWithParams(int index, int params) {
    return Collision_RunRayCast(gEntityMgr + 4 + index * 8, params);
}
