extern int data_ov025_020b574c[];
extern char data_ov025_020b4ab0[];

void Ov025_HandlerA_Call2(int arg0)
{
    int index = data_ov025_020b574c[0];

    if (index != -1) {
        ((void (*)(int))*(int *)(*(char **)(data_ov025_020b4ab0 + index * 8) + 8))(arg0);
    }
}
