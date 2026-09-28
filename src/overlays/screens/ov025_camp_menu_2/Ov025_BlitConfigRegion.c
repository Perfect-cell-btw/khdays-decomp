extern void Tween_Configure();
extern void Tween_Start();
extern int data_ov025_020b5744;

void Ov025_BlitConfigRegion(int arg0, unsigned int arg1) {
    Tween_Configure((unsigned int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95d8), 0,
                  *(unsigned int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95d4),
                  arg0 << 0xc, arg1);
    Tween_Start(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95d8);
}
