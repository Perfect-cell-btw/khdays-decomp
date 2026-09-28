void Ov088_ArmState3(void *self, int value)
{
    *(int *)((char *)self + 4) = 3;
    *(int *)((char *)self + 0x110) = value;
    *(int *)((char *)self + 0x114) = 0;
}
