/* Pick the ov259 actor's +8 target: kind 0 takes the nearest foe (020cab14), kind 1 the helper
 * pick of 020d15bc. */
extern int Ov107_FindNearestObject(int obj, int kind);
extern int Ov259_FindFarthestTarget(int obj, int kind);

void Ov259_PickTarget(int *node, int kind)
{
    int *state = (int *)node[1];

    switch (kind) {
    case 0:
        state[2] = Ov107_FindNearestObject(*state, 0);
        break;
    case 1:
        state[2] = Ov259_FindFarthestTarget(*state, 0);
        break;
    }
}
