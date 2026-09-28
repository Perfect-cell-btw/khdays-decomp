extern int data_ov008_02090f0c[];
extern char data_ov008_0209009c[];

void Ov008_HandlerA_Call2(int arg0)
{
    int index = data_ov008_02090f0c[0];

    if (index != -1) {
        ((void (*)(int))*(int *)(*(char **)(data_ov008_0209009c + index * 8) + 8))(arg0);
    }
}
