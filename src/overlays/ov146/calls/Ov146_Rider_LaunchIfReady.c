struct v3 { int x, y, z; };

extern int Ov146_Launch(int a, struct v3 v);

int Ov146_Rider_LaunchIfReady(int param_1, struct v3 param_2) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov146_Launch(*(int *)(param_1 + 0x214), param_2);
    }
    return param_1;
}
