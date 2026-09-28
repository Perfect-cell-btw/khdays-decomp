/* Dispatch veneer: indexes an 8-byte-stride table at data_0204c208 (field
 * at +4) by `index` and tail-calls the handler, forwarding the remaining
 * argument(s) untouched in r1(/r2). One of a shape-family (0202c208/228/248/
 * 3c4/3e4/404) differing only in target handler and forwarded-arg count. */
extern void *Collision_ProbeGround();
extern int data_0204c208;

void *EntityMgr_ProbeGround(int index, int arg2, int arg3) {
    return Collision_ProbeGround(data_0204c208 + 4 + index * 8, arg2, arg3);
}
