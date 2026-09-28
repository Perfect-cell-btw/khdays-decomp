/* Register two handler slots for the sub-object at param_1+0xe0 (types 0 and 2). */
extern void BindAnimTrack(int a, int b, int c, int d);

void Ov002_BindNodeTracks02(int param_1) {
    BindAnimTrack(param_1, 0, param_1 + 0xe0, 0);
    BindAnimTrack(param_1, 2, param_1 + 0xe0, 0);
}
