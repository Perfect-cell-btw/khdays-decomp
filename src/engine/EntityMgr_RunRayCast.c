/* Casts a ray against the collision of the indexed entity-manager world, with flags and an object
 * to exclude. */

typedef struct {
    int word0;
    int word4;
    int word8;
    unsigned short halfc;
    unsigned short halfe;
    int word10;
} func_0202c268_args;

extern char *data_0204c208;
extern void Collision_RunRayCast(void *ptr, func_0202c268_args *args);

void EntityMgr_RunRayCast(int index, int arg1, int arg2, int arg3) {
    func_0202c268_args args;

    args.word0 = arg1;
    args.word4 = arg2;
    args.halfc = 0;
    args.halfe = 0;
    args.word10 = arg3;
    Collision_RunRayCast(data_0204c208 + 4 + index * 8, &args);
}
