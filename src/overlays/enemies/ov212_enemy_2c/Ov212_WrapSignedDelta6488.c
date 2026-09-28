int Ov212_WrapSignedDelta6488(int a, int b)
{
    int diff = a - b;
    int mag = diff < 0 ? -diff : diff;
    if (mag < 0x3244)
        return diff;
    if (diff >= 0)
        return -(0x3244 * 2 - diff);
    return diff + 0x6488;
}
