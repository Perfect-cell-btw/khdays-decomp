/* Picks the tier to show: 0 when inactive or blocked, 1 below the threshold, 2 otherwise. */

int Ov008_SelectTierIfActive(int a, unsigned b, int c) {
    if (a != 0 && c == 0) {
        return b < 2 ? 1 : 2;
    }
    return 0;
}
