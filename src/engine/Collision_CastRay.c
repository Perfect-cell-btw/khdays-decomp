/* Casts a ray against the world's collision (Collision_RunRayCast) with the direction treated as a
 * unit vector. Returns the nearest hit record, or NULL when nothing is hit. */

typedef struct {
    int word0;
    int word4;
    int word8;
    unsigned short halfc;
    unsigned short halfe;
    int word10;
} func_01fff920_args;

extern void *Collision_RunRayCast(int arg0, func_01fff920_args *args);

void *Collision_CastRay(int arg0, int arg1, int arg2) {
    func_01fff920_args args;

    args.word0 = arg1;
    args.word4 = arg2;
    args.halfc = 1;
    return Collision_RunRayCast(arg0, &args);
}
