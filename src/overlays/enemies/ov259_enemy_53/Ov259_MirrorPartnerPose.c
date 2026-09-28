/* Mirror a pose on the ov259 actor's +0x414 partner: the 27-entry pose -> partner motion map
 * (data_ov259_020d2f90, -1 = none) picks the motion, played with the caller's mode. */
typedef struct { signed char motion[27]; } PartnerMotionMap;

extern void Ov107_StartAnim(int part, int motion, int mode);
extern const PartnerMotionMap data_ov259_020d2f90;

void Ov259_MirrorPartnerPose(int *node, int pose, int mode)
{
    int *state = (int *)node[1];
    PartnerMotionMap map = data_ov259_020d2f90;

    if (map.motion[pose] < 0) {
        return;
    }
    Ov107_StartAnim(*(int *)(*state + 0x414), map.motion[pose], mode);
}
