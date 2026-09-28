extern int Ov012_IsGlobalByte8be1Clear();
int Ov012_thumbStep_2(void) {
    if (Ov012_IsGlobalByte8be1Clear() != 0) return 1;
    return 0;
}
