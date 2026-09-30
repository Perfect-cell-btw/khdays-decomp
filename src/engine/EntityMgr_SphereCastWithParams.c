/* Casts a sphere (Collision_RunSphereCast) with ready-made cast parameters against the collision
 * of the entity manager's model group `index` (8-byte records from +4). EntityMgr_RunSphereCast
 * builds the parameters itself. */
extern void *Collision_RunSphereCast();
extern int gEntityMgr;

void *EntityMgr_SphereCastWithParams(int index, int params) {
    return Collision_RunSphereCast(gEntityMgr + 4 + index * 8, params);
}
