/* Refresh the three sub-panels that are in a settled state (0 or 1): the pair at
 * +0xe8 and +0x8cc share one gate at +0xd58, and the one at +0xdc0 has its own
 * at +0xfec. Does nothing with no context installed. */
extern void Ov002_ResetAndDrawNode(void *panel);

extern char *data_ov002_0207f628;

void Ov002_RefreshSettledPanels(void) {
    char *ctx = data_ov002_0207f628;

    if (ctx == 0) {
        return;
    }

    switch (*(int *)(ctx + 0xd58)) {
    case 0:
    case 1:
        Ov002_ResetAndDrawNode(ctx + 0xe8);
        Ov002_ResetAndDrawNode(ctx + 0x8cc);
        break;
    }

    switch (*(int *)(ctx + 0xfec)) {
    case 0:
    case 1:
        Ov002_ResetAndDrawNode(ctx + 0xdc0);
        break;
    }
}
