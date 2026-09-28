/* Move-change hook of the ov259 actor: moves 8-11 and 13 close the +0x384 rig's shells (020d1764
 * with 0), moves 16-18 open them. */
extern void Ov259_SwapShells(int rig, int open);

void Ov259_MoveHook(char *self, int move)
{
    switch (move) {
    case 16:
    case 17:
    case 18:
        Ov259_SwapShells(*(int *)(self + 0x384), 1);
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
        Ov259_SwapShells(*(int *)(self + 0x384), 0);
        break;
    }
}
