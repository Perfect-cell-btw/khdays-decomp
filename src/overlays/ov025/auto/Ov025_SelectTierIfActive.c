int Ov025_SelectTierIfActive(int a, unsigned b, int c) {
    if (a != 0 && c == 0) {
        return b < 2 ? 1 : 2;
    }
    return 0;
}
