/* Draw down the remaining byte budget at +0x4b4 by whatever the decoder consumed,
 * clamped at zero. Nothing to do once the budget is spent. */
extern int Ov022_GetGlobal34(int budget);

void Ov022_SpendDecodeBudget(char *self) {
    int left = *(int *)(self + 0x4b4);

    if (left == 0) {
        return;
    }

    left = *(int *)(self + 0x4b4) - Ov022_GetGlobal34(left);
    *(int *)(self + 0x4b4) = left;

    if (left < 0) {
        *(int *)(self + 0x4b4) = 0;
    }
}
