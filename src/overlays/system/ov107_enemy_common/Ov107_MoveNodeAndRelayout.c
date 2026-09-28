/* Ov107_MoveNodeAndRelayout -- refresh a node then re-run its layout, ov107.
 * 2nd parameter is unused here; real per callers in ov115/ov117/ov107. */
typedef struct { int x, y, z; } VecFx32;
extern void Srt_SetTranslation(void *sub);
extern void Ov107_UpdateCollisionSphere(void *node);
void Ov107_MoveNodeAndRelayout(char *node, VecFx32 *v) {
    Srt_SetTranslation(node + 0xa0);
    Ov107_UpdateCollisionSphere(node);
}
