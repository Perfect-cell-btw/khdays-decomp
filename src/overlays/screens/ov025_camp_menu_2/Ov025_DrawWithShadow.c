extern int Text_DrawDirectional_2();

void Ov025_DrawWithShadow(int a, int b, int c, int d, int e, int sel) {
    int pool;
    switch (sel) {
    case 1:
        pool = 0x821;
        break;
    case 2:
        pool = 0x411;
        break;
    default:
        pool = 0x209;
        break;
    }
    Text_DrawDirectional_2(a, b + 1, c + 1, 1, pool, e);
    Text_DrawDirectional_2(a, b, c, d, pool, e);
}
