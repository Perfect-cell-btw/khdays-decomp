extern long long OS_GetTick(void);

struct obj {
    int _pad[4];
    long long value;
    unsigned flag0 : 1;
    unsigned flag1 : 1;
    unsigned flag2 : 1;
};

void Tween_Start(struct obj *o) {
    o->value = OS_GetTick();
    o->flag0 = 1;
    o->flag1 = 0;
    o->flag2 = 0;
}
