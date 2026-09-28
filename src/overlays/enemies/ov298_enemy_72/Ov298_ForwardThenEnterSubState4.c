struct bf { unsigned b : 8; };

extern void Ov298_DashSetup(void *node);

void Ov298_ForwardThenEnterSubState4(int *node) {
    int *state = (int *)node[1];

    Ov298_DashSetup(node);

    if (*(unsigned char *)(state[1] + 0xad) != 0) return;

    state[0x24] = 0;
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    *(unsigned char *)(*state + 0x1c7) = 4;
}
