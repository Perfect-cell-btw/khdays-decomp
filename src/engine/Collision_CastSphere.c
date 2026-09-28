typedef struct {
    int word0;
    int word4;
    int word8;
    unsigned short halfc;
    unsigned short halfe;
    int word10;
} func_01fff948_args;

extern void Collision_RunSphereCast(int arg0, func_01fff948_args *args);

void Collision_CastSphere(int arg0, int arg1, int arg2, int arg3) {
    func_01fff948_args args;

    args.word0 = arg1;
    args.word4 = arg2;
    args.word8 = arg3;
    args.halfc = 1;
    Collision_RunSphereCast(arg0, &args);
}
