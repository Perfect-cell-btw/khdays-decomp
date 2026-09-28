/* Forward the pair to Ov002_SetScrollPosition_2, first publishing request kind 9 when
 * the caller asked for it AND the context's busy word at +0x1b8 is clear. */
extern void Ov002_PublishRequestKind9(void);
extern void Ov002_SetScrollPosition_2(int a, int b);

extern char *data_ov002_0207f614;

void Ov002_ForwardWithOptionalPublish(int a, int b) {
    char *ctx = data_ov002_0207f614;

    if (*(int *)(ctx + 0x1b8) == 0 && b != 0) {
        Ov002_PublishRequestKind9();
    }
    Ov002_SetScrollPosition_2(a, b);
}
