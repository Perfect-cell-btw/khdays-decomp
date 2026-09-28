/* When the object is active, stores its position (+0xa8), rewinds its four animation tracks,
 * restores its base value unless flag 0x10, and marks it updated. */

extern int Ov022_IsBit0Set_5(int arg0);
extern void Anim_SetFrameWrapped(int arg0, int arg1, int arg2);

struct Vec3_020941a0 { int a, b, c; };

void Ov022_ApplyVec3AndResetTracks(int arg0, int arg1) {
    if (Ov022_IsBit0Set_5(arg0)) {
        *(struct Vec3_020941a0 *)(arg0 + 0xa8) = *(struct Vec3_020941a0 *)arg1;
        Anim_SetFrameWrapped(arg0 + 4, 0, 0);
        Anim_SetFrameWrapped(arg0 + 4, 2, 0);
        Anim_SetFrameWrapped(arg0 + 4, 3, 0);
        Anim_SetFrameWrapped(arg0 + 4, 1, 0);
        if ((*(unsigned char *)arg0 & 0x10) == 0)
            *(int *)(arg0 + 0x10c) = *(int *)(arg0 + 0x118);
        *(unsigned char *)arg0 |= 0x20;
    }
}
