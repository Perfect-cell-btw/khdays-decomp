/* Sound-cue tick of the ov259 enemy: the +0x70 clock runs up at the frame rate (capped at 39.84) and,
 * in phases 11 (six cues), 16 (six) and 17 (eleven) of +0xae, each +0xa8 step plays its sound 0x172
 * variants (020cd3c4) once the clock passes the step's time, advancing +0xa8. */
typedef unsigned short u16;

extern void Ov259_PlaySound(int actor, int id, u16 mode, int at);

void Ov259_SoundCueTick(int *node)
{
    int *state = (int *)node[1];
    int phase;

    if (state[0x1c] < 0x27d80) {
        state[0x1c] += *(int *)(node[0] + 0x2c);
    }
    phase = *(signed char *)((char *)state + 0xae);
    if (phase == 0) {
        return;
    }
    switch (phase) {
    case 11:
        switch (state[0x2a]) {
        case 0:
            if (state[0x1c] > 0x3b8) {
                Ov259_PlaySound(*state, 0x172, 0x8, state[4]);
                state[0x2a]++;
            }
            break;
        case 1:
            if (state[0x1c] > 0x660) {
                Ov259_PlaySound(*state, 0x172, 0x18, state[4]);
                state[0x2a]++;
            }
            break;
        case 2:
            if (state[0x1c] > 0xff0) {
                Ov259_PlaySound(*state, 0x172, 0xa, state[4]);
                state[0x2a]++;
            }
            break;
        case 3:
            if (state[0x1c] > 0x1210) {
                Ov259_PlaySound(*state, 0x172, 0x1a, state[4]);
                state[0x2a]++;
            }
            break;
        case 4:
            if (state[0x1c] > 0x1650) {
                Ov259_PlaySound(*state, 0x172, 0x9, state[4]);
                state[0x2a]++;
            }
            break;
        case 5:
            if (state[0x1c] > 0x17e8) {
                Ov259_PlaySound(*state, 0x172, 0x19, state[4]);
                state[0x2a]++;
            }
            break;
        }
        break;
    case 16:
        switch (state[0x2a]) {
        case 0:
            if (state[0x1c] > 0x990) {
                Ov259_PlaySound(*state, 0x172, 0xa, state[4]);
                Ov259_PlaySound(*state, 0x172, 0x19, state[4]);
                state[0x2a]++;
            }
            break;
        case 1:
            if (state[0x1c] > 0xff0) {
                Ov259_PlaySound(*state, 0x172, 0x8, state[4]);
                state[0x2a]++;
            }
            break;
        case 2:
            if (state[0x1c] > 0x1650) {
                Ov259_PlaySound(*state, 0x172, 0xe, state[4]);
                Ov259_PlaySound(*state, 0x172, 0x18, state[4]);
                state[0x2a]++;
            }
            break;
        case 3:
            if (state[0x1c] > 0x1d38) {
                Ov259_PlaySound(*state, 0x172, 0xd, state[4]);
                state[0x2a]++;
            }
            break;
        case 4:
            if (state[0x1c] > 0x2310) {
                Ov259_PlaySound(*state, 0x172, 0x10, state[4]);
                state[0x2a]++;
            }
            break;
        case 5:
            if (state[0x1c] > 0x2b90) {
                Ov259_PlaySound(*state, 0x172, 0x1a, state[4]);
                state[0x2a]++;
            }
            break;
        }
        break;
    case 17:
        switch (state[0x2a]) {
        case 0:
            if (state[0x1c] > 0x908) {
                Ov259_PlaySound(*state, 0x172, 0xa, state[4]);
                state[0x2a]++;
            }
            break;
        case 1:
            if (state[0x1c] > 0x1650) {
                Ov259_PlaySound(*state, 0x172, 0xd, state[4]);
                state[0x2a]++;
            }
            break;
        case 2:
            if (state[0x1c] > 0x1d38) {
                Ov259_PlaySound(*state, 0x172, 0xb, state[4]);
                state[0x2a]++;
            }
            break;
        case 3:
            if (state[0x1c] > 0x1fe0) {
                Ov259_PlaySound(*state, 0x172, 0xa, state[4]);
                state[0x2a]++;
            }
            break;
        case 4:
            if (state[0x1c] > 0x29f8) {
                Ov259_PlaySound(*state, 0x172, 0xe, state[4]);
                state[0x2a]++;
            }
            break;
        case 5:
            if (state[0x1c] > 0x2f48) {
                Ov259_PlaySound(*state, 0x172, 0x8, state[4]);
                state[0x2a]++;
            }
            break;
        case 6:
            if (state[0x1c] > 0x3520) {
                Ov259_PlaySound(*state, 0x172, 0x9, state[4]);
                state[0x2a]++;
            }
            break;
        case 7:
            if (state[0x1c] > 0x3fc0) {
                Ov259_PlaySound(*state, 0x172, 0x9, state[4]);
                state[0x2a]++;
            }
            break;
        case 8:
            if (state[0x1c] > 0x5148) {
                Ov259_PlaySound(*state, 0x172, 0x10, state[4]);
                state[0x2a]++;
            }
            break;
        case 9:
            if (state[0x1c] > 0x5940) {
                Ov259_PlaySound(*state, 0x172, 0x9, state[4]);
                state[0x2a]++;
            }
            break;
        case 10:
            if (state[0x1c] > 0x97f0) {
                Ov259_PlaySound(*state, 0x172, 0x17, state[4]);
                state[0x2a]++;
            }
            break;
        }
        break;
    }
}
