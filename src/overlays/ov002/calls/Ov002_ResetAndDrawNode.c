extern int Ov002_DrawAndStepNode();

int Ov002_ResetAndDrawNode(int arg0) {
    *(int *)(arg0 + 0xb8) = 0;
    *(int *)(arg0 + 0xb4) = 0;
    *(int *)(arg0 + 0xb0) = 0;
    return Ov002_DrawAndStepNode(arg0);
}
