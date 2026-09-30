/* Dispatch veneer: indexes an 8-byte-stride table at gEntityMgr (field
 * at +4) by `index` and tail-calls the handler, forwarding the remaining
 * argument(s) untouched in r1(/r2). One of a shape-family (0202c208/228/248/
 * 3c4/3e4/404) differing only in target handler and forwarded-arg count. */
extern void *CollModel_GetEntryField14();
extern int gEntityMgr;

void *EntityMgr_GetCollEntryField14(int index, int arg2) {
    return CollModel_GetEntryField14(gEntityMgr + 4 + index * 8, arg2);
}
