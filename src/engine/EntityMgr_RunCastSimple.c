/* Builds a cast parameter block and runs the collision cast on entity slot index. Returns the
 * nearest hit record, or NULL when nothing is hit. */

typedef struct {
    int word0;
    int word4;
    int word8;
    unsigned short halfc;
    unsigned short halfe;
    int word10;
} func_0202c2f8_args;

extern char *data_0204c208;
extern void *Collision_CastNearest(void *ptr, func_0202c2f8_args *args);

void *EntityMgr_RunCastSimple(int index, int arg1, int arg2, int arg3) {
    func_0202c2f8_args args;

    args.word0 = arg1;
    args.word4 = arg2;
    args.halfc = 0;
    args.halfe = 0;
    args.word10 = arg3;
    return Collision_CastNearest(data_0204c208 + 4 + index * 8, &args);
}
