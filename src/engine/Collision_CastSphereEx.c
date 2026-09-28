/* Casts a sphere against the world's collision (Collision_RunSphereCast) with flags and an object
 * to exclude. Returns the nearest hit record, or NULL when nothing is hit. */

typedef struct {
    int word0;
    int word4;
    int word8;
    unsigned short halfc;
    unsigned short halfe;
    int word10;
} func_01fff8e8_args;

extern void *Collision_RunSphereCast(int arg0, func_01fff8e8_args *args);

void *Collision_CastSphereEx(int arg0, int arg1, int arg2, int arg3, int arg4) {
    func_01fff8e8_args args;

    args.word0 = arg1;
    args.word4 = arg2;
    args.word8 = arg3;
    args.halfc = 0;
    args.halfe = 0;
    args.word10 = arg4;
    return Collision_RunSphereCast(arg0, &args);
}
