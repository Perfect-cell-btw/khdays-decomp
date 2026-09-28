extern int data_ov008_02090f0c[];
extern char data_ov008_02090064[];

void Ov008_HandlerB_Call1(int arg0)
{
    int index = data_ov008_02090f0c[1];

    if (index != -1) {
        ((void (*)(int))*(int *)(*(char **)(data_ov008_02090064 + index * 8) + 4))(arg0);
    }
}
